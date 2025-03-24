#include "JsonParser.h"
#include <iostream>
#include <sstream>
#include <optional>

bool JsonParser::loadFromFile(std::string_view filePath)
{
    std::ifstream configFile (filePath.data());
    if(!configFile.is_open()){
        std::cerr << "Error: enable to open file for reading" << std::endl; 
        return false;
    }
    
    try {
        configFile >> config;
    } catch (const json::parse_error& er) {
        std::cerr << "Error[extract settings from config file]: " << er.what() << std::endl; 
        configFile.close();
        return false;
    }

    configFile.close();
    return true;
}

bool JsonParser::saveToFile(std::string_view fileOutPath, size_t dump)
{
    std::ofstream outputFile(fileOutPath.data());
    if(!outputFile.is_open()){
        std::cerr << "Error: enable to open file for writting!!!" << std::endl;
        return false;
    }

    outputFile << config.dump(dump);
    outputFile.close();
    return true;
}

nlohmann::json JsonParser::getSetting(std::string_view key) const
{
    std::istringstream iss(key.data());
    std::string token;

    const nlohmann::json* current = &config;

    while(std::getline(iss, token, '.')){
        if(!current -> contains(token)){
            return "";
        }
        current = &(*current)[token];
    }
    return *current;
}


void JsonParser::setSetting(std::string_view key, nlohmann::json value)
{
    std::istringstream iss(key.data());
    std::string token;

    nlohmann::json *current = &config;

    while(std::getline(iss, token, '.')){
        current = &(*current)[token];
    }
    *current = value;
}

void JsonParser::showSettings() const
{
    std::cout << config.dump(4);
}


/* example of usage
    auto& jsonParser = ConfigurationManager::getInstance();
    jsonParser.setParser(std::make_unique<JsonParser>());
    jsonParser.setParser(std::make_unique<JsonParser>()); // won't work

    jsonParser.setSetting("settings.resolution.height", 720);
    jsonParser.setSetting("settings.fullscreen", false);
    jsonParser.setSetting("user.name", "Alice");
    jsonParser.setSetting("features", nlohmann::json::array({"autosave", "sync"}));
    jsonParser.setSetting("settings.new_block", nlohmann::json{{"key1", 123}, {"key2", "abc"}});

    jsonParser.saveToFile("config_edited.json");
*/