#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>

class User {
    private:
        size_t levelOfSubrsription;
        std::string userName;
        std::unordered_set<std::string> watchLaterList;
        const std::string userId;
        const size_t HISTORY_SIZE = 10;
        const size_t WATCH_LATER_SIZE = 5;
        std::unordered_map<std::string, std::list<std::string>::iterator> seen;
        std::list<std::string> history;
        
        std::string getUserId(const std::string userName) const;
        void upgradeSubscriptionHelper(size_t price, size_t& money);
    public:
        explicit User(const std::string& _userName);
        
        void getWatchLaterList() const;
        void getWatchHistory() const;
        size_t getLevelOfSubscription() const;
        std::string getUserId() const;
        void upgradeSubscription(size_t money);
        void addVideoToHistory(const std::string& url);
        void addVideoToLaterWatchList(const std::string& url);
};

#endif // USER_H