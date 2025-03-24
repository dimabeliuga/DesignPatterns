#include "ConfigurationManager.h"
#include <iostream>

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
    if(!isPointerInitialized()){
        fileParser = std::move(parser);
    } else {
        std::cout << "Warning: you have already set the parser\n";
    }
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

void ConfigurationManager::setSetting(std::string_view key, nlohmann::json value) {
    if(isPointerInitialized()){
        fileParser -> setSetting(key, value);
    }
}

void ConfigurationManager::showSettings() const
{
    if(isPointerInitialized()){
        fileParser -> showSettings();
    }
}



