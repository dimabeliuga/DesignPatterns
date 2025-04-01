#include "ProxyVideoService.h"
#include <regex>

/* void ProxyVideoService::VideoCache::resetDatas() {
    if(videoName.has_value())        { videoName.reset(); }
    if(duration.has_value())         { duration.reset();  }
    if(authorInfo.has_value())       { authorInfo.reset();}
    if(videoDescription.has_value()) { videoDescription.reset(); }
    std::cout << "Reset\n";
}
 */
ProxyVideoService::ProxyVideoService(std::shared_ptr<User> _user)
        : user(_user), realVideoService(std::make_unique<VideoService>())
{
    LoggerConfigBuilder().setupLogger();
    LOG_INFO("Proxy Video Servic has been created");
}

void ProxyVideoService::updateCache(const std::string& url) const {
    if(!isUrlValid(url)){
        throw std::invalid_argument("Invalid url adress. Try again...");
    }

    auto it = cache.find(url);
    if(it != cache.end()){
        lruOrder.erase(it->second.second);
        lruOrder.push_front(url);
        it->second.second = lruOrder.begin();
        LOG_INFO("The Url which is in the cache was used");
    } else {
        if (cache.size() >= MAX_CACHE_SIZE) {
            std::string oldUrl = lruOrder.back();
            lruOrder.pop_back();
            cache.erase(oldUrl); 
            LOG_INFO("Old element was deleted to place new one");
        }
        lruOrder.push_front(url);
        cache.emplace(url, std::make_pair(VideoCache(), lruOrder.begin()));
    }
}

bool ProxyVideoService::isUrlValid(const std::string& url) const {
    const static std::regex pattern (R"(^(?:https?:\/\/)?(?:www\.)?(?:youtube\.com\/(?:watch\?(?:.*&)?v=|embed\/)|youtu\.be\/)([A-Za-z0-9_-]{11})(?:\S+)?$)", std::regex::optimize);
    if(std::regex_match(url, pattern)){
        return true;
    }
    return false;
}

ProxyVideoService::VideoCache& ProxyVideoService::getCacheEntry(const std::string &url) const 
{
    return cache[url].first;
}

bool ProxyVideoService::checkUserSubsctiption(size_t level) const
{
    if(user -> getLevelOfSubscription() < level){
        LOG_WARN("You level of the subsctiption doesn't allow you to use this feature");
        return false;
    }
    return true;
}

void ProxyVideoService::setUser(std::unique_ptr<User> _user)
{
    user = std::move(_user);
}

void ProxyVideoService::playVideo(const std::string url) const
{
    if(isUrlValid(url)) {
        realVideoService -> playVideo(url);
    } else {
        std::cerr << "The url: " << url << " is not valid. Check the url and try again!!!" << std::endl; 
    }
}

size_t ProxyVideoService::getVideoDuration(std::string url) const {
    if(!checkUserSubsctiption(SECOND_LEVEL_OF_SUBSCRIPTION)){
        // throw std::invalid_argument("Not enough level of the subsctiption");
        return 0;
    }
    updateCache(url);
    if(!getCacheEntry(url).duration.has_value()){
        getCacheEntry(url).duration = realVideoService -> getVideoDuration(url);
    }
    user -> addVideoToHistory(url);
    return getCacheEntry(url).duration.value();
}

std::string ProxyVideoService::getVideoName(const std::string url) const {
    if(checkUserSubsctiption(SECOND_LEVEL_OF_SUBSCRIPTION)){
        return "";
    }
    updateCache(url);
    if(!getCacheEntry(url).videoName.has_value()){
        getCacheEntry(url).videoName = realVideoService -> getVideoName(url);
    }
    user -> addVideoToHistory(url);
    return getCacheEntry(url).videoName.value();
}


std::string ProxyVideoService::getAuthorInfo(std::string url) const {
    if(!checkUserSubsctiption(THIRD_LEVEL_OF_SUBSCRIPTION)){
        return "";
    }
    updateCache(url);
    if(!getCacheEntry(url).authorInfo.has_value()){
        getCacheEntry(url).authorInfo= realVideoService -> getAuthorInfo(url);
    }
    user -> addVideoToHistory(url);
    return getCacheEntry(url).authorInfo.value();
}

std::string ProxyVideoService::getVideoDescription(std::string url) const {
    if(!checkUserSubsctiption(THIRD_LEVEL_OF_SUBSCRIPTION)){
        return "";
    }
    updateCache(url);
    if(!getCacheEntry(url).videoDescription.has_value()){
        getCacheEntry(url).videoDescription = realVideoService -> getVideoName(url);
    }
    user -> addVideoToHistory(url);
    return getCacheEntry(url).videoDescription.value();
}
