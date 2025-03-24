#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

class FileParser {
    public:
        FileParser() = default;
        virtual ~FileParser() = default;
        virtual nlohmann::json getSetting(std::string_view key) const = 0;
        virtual bool loadFromFile(std::string_view filePath) = 0;
        virtual bool saveToFile(std::string_view fileOutPath, size_t dump) = 0;
        virtual void showSettings() const = 0;
        virtual void setSetting(std::string_view key, nlohmann::json value) = 0;
};

#endif //CONFIGURATION_H