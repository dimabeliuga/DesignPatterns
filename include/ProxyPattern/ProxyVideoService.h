#ifndef PROXY_VIDEO_SERVICE_H
#define PROXY_VIDEO_SERVICE_H

#include "Video.h"
#include "RealVideoService.h"
#include "logger.h"
#include "User.h"
#include <list>
#include <unordered_map>
#include <optional>
#include <string>
#include <utility>


class ProxyVideoService : public Video {
    private:
        // struct for storing a video data. It will be used in cache algorithm
        struct VideoCache {
            std::optional<std::string> videoName;
            std::optional<size_t> duration;
            std::optional<std::string> authorInfo;
            std::optional<std::string> videoDescription;
            // void resetDatas();
        };
        
        std::unique_ptr<VideoService> realVideoService;
        std::shared_ptr<User> user;
        // I use lru cache algorithm
        mutable std::list<std::string> lruOrder;
        mutable std::unordered_map<std::string, std::pair<VideoCache, std::list<std::string>::iterator>> cache;

        static const size_t SECOND_LEVEL_OF_SUBSCRIPTION = 2;
        static const size_t THIRD_LEVEL_OF_SUBSCRIPTION = 3; 
        static const size_t MAX_CACHE_SIZE = 5;

        void updateCache(const std::string& url) const;
        bool isUrlValid(const std::string& url) const;
        VideoCache& getCacheEntry(const std::string& url) const;
        bool checkUserSubsctiption(size_t level) const;
    public:
        explicit ProxyVideoService(std::shared_ptr<User> _user);

        void setUser(std::unique_ptr<User> _user);
        void playVideo(std::string url) const override;
        size_t getVideoDuration(std::string url) const override;
        std::string getVideoName(std::string url) const override;
        std::string getAuthorInfo(std::string url) const override;
        std::string getVideoDescription(std::string url) const override;
};

#endif // PROXY_VIDEO_SERVICE_H



/*
VideoService videoService;
    std::string url = "https://www.youtube.com/watch?v=8wwD-Jnveso";
    std::cout << "Author : " << videoService.getAuthorInfo(url) << std::endl;
    std::cout << "Video name : " << videoService.getVideoName(url) << std::endl;
    std::cout << "Video duration : " << videoService.getVideoDuration(url) << std::endl;
    std::cout << "Video description : " << videoService.getVideoDescription(url) << std::endl;
    videoService.playVideo(url);
        
    std::string url[] { "https://www.youtube.com/watch?v=8wwD-Jnveso",
                        "https://www.youtube.com/watch?v=vlPgD1y5BBk",
                        "https://www.youtube.com/watch?v=9VUIFbht-LU",
                        "https://www.youtube.com/watch?v=MKG_6BqnhpI",
                        "https://www.youtube.com/watch?v=LcR8SYiLU74",
                        "https://www.youtube.com/watch?v=lKCsQ2hQ7NI"};

    std::shared_ptr<User> user = std::make_unique<User>("max");
    user -> addVideoToLaterWatchList(url[0]);
    user -> addVideoToLaterWatchList(url[1]);
    user -> addVideoToLaterWatchList(url[2]);
    user -> addVideoToLaterWatchList(url[3]);
    user -> addVideoToLaterWatchList(url[4]);
    user -> addVideoToLaterWatchList(url[5]);
    user -> addVideoToLaterWatchList(url[0]);
    user -> addVideoToLaterWatchList(url[1]);
    user -> addVideoToLaterWatchList(url[2]);

    user -> getWatchLaterList();
    user -> upgradeSubscription(100);
    user -> upgradeSubscription(100);
    ProxyVideoService service(user);

    service.getVideoDuration(url[0]);
    service.getAuthorInfo(url[1]);
    service.getVideoDescription(url[2]);
    service.getVideoDuration(url[3]);
    service.getVideoDuration(url[4]);
    service.getVideoDuration(url[5]);
    service.getVideoDuration(url[0]);
    service.getVideoDuration(url[1]);
    service.getVideoDuration(url[2]);
    
    user -> getWatchHistory();
    
*/