#include "ConfigurationManager.h"
#include <iostream>

int main() {
    /* auto& jsonParser = ConfigurationManager::getInstance();
    jsonParser.setParser(std::make_unique<JsonParser>());
    jsonParser.loadFromFile("config.json");
    jsonParser.showSettings();
    jsonParser.saveToFile("config_changed.json");
    auto& jsonParserClone = ConfigurationManager::getInstance();
    std::cout << jsonParserClone.getSetting("name") << '\n';
    // std::cout << jsonParserClone.getSetting("features") << '\n';
    std::cout << jsonParserClone.getSetting("version") << '\n';
    std::cout << jsonParserClone.getSetting("las_login");
     */
    /* auto version = jsonParser.getSetting("version");
    std::cout << "Version: " << version.dump(4);
    auto effects = jsonParser.getSetting("settings.volume");
    std::cout << "\n\n User: " << effects.dump(4) << "\n";
     */
    auto& jsonParser = ConfigurationManager::getInstance();
    jsonParser.setParser(std::make_unique<JsonParser>("config.json"));
    jsonParser.setSetting("settings.resolution.height", 720);
    jsonParser.setSetting("settings.fullscreen", false);
    jsonParser.setSetting("user.name", "Alice");
    jsonParser.saveToFile("config_edited.json");

    
    return 0;
}