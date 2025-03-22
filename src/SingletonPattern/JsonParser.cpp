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

JsonParser::JsonParser(std::string_view filePath){
    loadFromFile(filePath);
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

void JsonParser::showSettings() const
{
    std::cout << config.dump(4);
}
