#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "Configuration.h"

class JsonParser : public FileParser {
    private:
        json config;
    public:
        JsonParser() = default;
        JsonParser(std::string_view filePath);
        nlohmann::json getSetting(std::string_view key) const override;
        bool saveToFile(std::string_view fileOutPath, size_t dump = 4) override;
        void showSettings() const override;
        bool loadFromFile(std::string_view filePath) override;
        
        template<typename T>
        void setSetting(std::string_view key, T value)
        {
            std::istringstream iss(key.data());
            std::string token;

            nlohmann::json *current = &config;
        
            while(std::getline(iss, token, '.')){
                if(current -> contains(token)){
                    current = &(*current)[token];
                } else {
                    break;
                }
            }
            *current = key;
        }
    };
    

#endif //JSON_PARSER_H