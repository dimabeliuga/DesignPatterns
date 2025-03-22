#include "ConfigurationManager.h"

bool ConfigurationManager::isPointerInitialized() const
{
    return (fileParser != nullptr);
}

ConfigurationManager &ConfigurationManager::getInstance()
{
    static ConfigurationManager instance;
    return instance;
}

void ConfigurationManager::setParser(std::unique_ptr<FileParser> parser){
    fileParser = std::move(parser);
}

bool ConfigurationManager::loadFromFile(std::string_view filePath)
{
    if(isPointerInitialized()){
        return fileParser -> loadFromFile(filePath);
    }
    return false;
}

bool ConfigurationManager::saveToFile(std::string_view fileOutPath, size_t dump)
{
    if(isPointerInitialized()){
        return fileParser -> saveToFile(fileOutPath, dump);
    }
    return false;
}

nlohmann::json ConfigurationManager::getSetting(std::string_view key) const
{
    if(isPointerInitialized()){
        return fileParser -> getSetting(key);
    }
    return false;
}

void ConfigurationManager::showSettings() const
{
    if(isPointerInitialized()){
        fileParser -> showSettings();
    }
}



