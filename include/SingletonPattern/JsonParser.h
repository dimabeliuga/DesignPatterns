#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "Configuration.h"

class JsonParser : public FileParser {
    private:
        json config;
    public:
        JsonParser() = default;
        nlohmann::json getSetting(std::string_view key) const override;
        bool saveToFile(std::string_view fileOutPath, size_t dump = 4) override;
        void showSettings() const override;
        bool loadFromFile(std::string_view filePath) override;
        void setSetting(std::string_view key, nlohmann::json value) override;
};


#endif //JSON_PARSER_H