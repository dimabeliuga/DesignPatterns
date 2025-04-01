#include "User.h"
#include <random>
#include <iostream>


User::User(const std::string& _userName) 
        : userName(_userName), 
        userId(getUserId(_userName)),
        levelOfSubrsription (1)
    {
    }

void User::getWatchLaterList() const
{
    std::cout << userName << " - your list of videos you wanted to watch later" << std::endl;
    for(const auto& iter : watchLaterList) {
        std::cout << iter << std::endl;
    }
    std::cout << "You have " << watchLaterList.size() << " videos in your watch later list" << std::endl;
}

void User::getWatchHistory() const
{
    std::cout << userName << " - your watch history" << std::endl;
    for(const auto& iter : history) {
        std::cout << iter << std::endl;
    }
}
size_t User::getLevelOfSubscription() const
{
    return levelOfSubrsription;
}
std::string User::getUserId() const
{
    return userId;
}
void User::upgradeSubscription(size_t money)
{
    switch (levelOfSubrsription)
    {
    case 1:
        upgradeSubscriptionHelper(10, money);
        break;
    case 2:
        upgradeSubscriptionHelper(20, money);
        break;
    case 3:
        std::cout << "You have the highest level of the subscription" << std::endl;
        break;
    default:
        break;
    }
}
void User::addVideoToHistory(const std::string& url)
{
    auto it = seen.find(url);
    if(it != seen.end()){
        history.erase(it->second);
    }
    history.push_back(url);
    seen[url] = std::prev(history.end());

    if(seen.size() > HISTORY_SIZE){
        const std::string& oldUrl = history.front();
        history.pop_front();
        seen.erase(oldUrl);
    }
}
void User::addVideoToLaterWatchList(const std::string &url)
{
    auto it = watchLaterList.find(url);
    if(it != watchLaterList.end()){
        std::cout << "The video is already in your watch later list" << std::endl;
    } else {
        watchLaterList.insert(url);
        std::cout << "The video was added to your watch later list" << std::endl;
    }
    if(watchLaterList.size() > WATCH_LATER_SIZE){
        std::cout << "You have too many videos in your watch later list. The first one was deleted" << std::endl;
        watchLaterList.erase(watchLaterList.begin());
    }
}
std::string User::getUserId(const std::string key) const
{
    size_t userIdLength = 12;
    std::hash <std::string> keyToHash;
    auto seed = static_cast<unsigned int>(keyToHash(key));

    std::mt19937 generator(seed);
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    static std::uniform_int_distribution<size_t> distribution(0, characters.size() - 1);

    std::string result;
    result.reserve(userIdLength);

    for (size_t i = 0; i < userIdLength; ++i) {
        result += characters[distribution(generator)];
    }

    return result;
}

void User::upgradeSubscriptionHelper(size_t price, size_t &money)
{
    if(money < price){
        std::cout << "Not enough money. The subsctiption costs = " << price << std::endl;
    } else {
        ++levelOfSubrsription;
    }
}
