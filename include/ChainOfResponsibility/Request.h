#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <random>


enum class REQUEST_CATEGORY {
    SOFTWARE,
    HARDWARE,
    NETWORKING,
    SECURITY,
    OTHER
};

enum class DIFFICULTY_LEVEL {
    LOW,
    MEDIUM,
    HIGH
};

/// @brief class Request is used to create a request object
/// @details The Request class is used to create a request object. It contains the following attributes:
/// @param description: a string that describes the request
/// @param category: an enum that describes the category of the request (SOFTWARE, HARDWARE, NETWORKING, SECURITY, OTHER)
/// @param difficultyLevel: an enum that describes the difficulty level of the request (LOW, MEDIUM, HIGH)
/// @param userId: a uint32_t that describes the user id of the user who created the request
/// @param isPriority: a bool that describes whether the request is a priority request or not
/// @param requestId: a uint32_t that describes the request id of the request
/// @note The request id is generated randomly between 1 and 1000000

class Request {
    private:
        std::string description;
        REQUEST_CATEGORY category;
        DIFFICULTY_LEVEL difficultyLevel;
        uint32_t userId;
        bool isPriority;
        uint32_t requestId;

        uint32_t generateRequestId() {
            static std::random_device rd;
            static std::mt19937 mt(rd());
            static std::uniform_int_distribution<uint32_t> dist(1, 1000000);
            return dist(mt);
        }

    public:
        Request(const std::string& _description, REQUEST_CATEGORY _category, DIFFICULTY_LEVEL _difficultyLevel, uint32_t _userId, bool _isPriority)
              : description(_description), 
                category(_category), 
                difficultyLevel(_difficultyLevel), 
                userId(_userId), 
                isPriority(_isPriority), 
                requestId(generateRequestId()) 
            {
            }

        std::string getDescription() const { return description; }
        REQUEST_CATEGORY getCategory() const { return category; }
        DIFFICULTY_LEVEL getDifficultyLevel() const { return difficultyLevel; }
        uint32_t getUserId() const { return userId; }
        bool isPriorityRequest() const { return isPriority; }
        uint32_t getRequestId() const { return requestId; }


};

#endif // REQUEST_H