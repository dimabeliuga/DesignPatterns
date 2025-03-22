#ifndef CONFIGURATION_MANAGER_H
#define CONFIGURATION_MANAGER_H

#include "Configuration.h"
#include "JsonParser.h"
#include <memory>

class ConfigurationManager : public FileParser{
    private:
        ConfigurationManager() = default;
        
        bool isPointerInitialized() const;

        std::unique_ptr<FileParser> fileParser;

    public:
        ConfigurationManager(const ConfigurationManager&) = delete;
        ConfigurationManager(ConfigurationManager&&) noexcept = delete;
        ConfigurationManager& operator=(const ConfigurationManager&) = delete;
        ConfigurationManager& operator=(ConfigurationManager&&) noexcept = delete;
        
        static ConfigurationManager& getInstance();
        void setParser(std::unique_ptr<FileParser> parser);

        nlohmann::json getSetting(std::string_view key) const override;
        bool saveToFile(std::string_view fileOutPath, size_t dump = 4) override;
        void showSettings() const override;
        bool loadFromFile(std::string_view filePath) override;

        template<typename T>
        void setSetting(std::string_view key, T value) {
            if(isPointerInitialized()){
                fileParser -> setSetting(key, value);
            }
        }
};
#endif //CONFIGURATION_MANAGER_H