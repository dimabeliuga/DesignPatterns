cmake_minimum_required(VERSION 3.20)
project(DesignPatterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#add_custom_target(run-cppcheck
#    COMMAND cppcheck --enable=all --inconclusive --suppress=missingIncludeSystem --output-file=cppcheck_report.txt
#        -I ${CMAKE_SOURCE_DIR}/include/AbstractFactory/
#        -I ${CMAKE_SOURCE_DIR}/include/AdapterPattern/
#        -I ${CMAKE_SOURCE_DIR}/include/BuilderPattern/
#        -I ${CMAKE_SOURCE_DIR}/include/FactoryMethod/
#        src/
#    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#    COMMENT "Running Cppcheck..."
#)

# AbstractFactory library
#add_library(AbstractFactory STATIC
#                src/AbstractFactory/WorldFactory.cpp
#               )                
#target_include_directories(AbstractFactory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/AbstractFactory)

# AdapterPattern library
#add_library(AdapterPattern STATIC 
#                src/AdapterPattern/Adapter.cpp
#                )
#target_include_directories(AdapterPattern PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/AdapterPattern)

# BuilderPattern library
#add_library(BuilderPattern STATIC
#                src/BuilderPattern/Builders.cpp
#                src/BuilderPattern/TravelDirector.cpp
#                )
#target_include_directories(BuilderPattern PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/BuilderPattern)

#Factory Design Method library
#add_library(FactoryMethod STATIC 
#                src/FactoryMethod/Transport.cpp
#                src/FactoryMethod/TransportCreator.cpp
#                src/FactoryMethod/CargoCreator.cpp
#                )
#target_include_directories(FactoryMethod 
#                            PUBLIC 
#                            ${CMAKE_CURRENT_SOURCE_DIR}/include/FactoryMethod)

#Prototype Pattern
#add_library(PrototypePattern STATIC 
#                src/PrototypePattern/CharcterPrototype.cpp
#                src/PrototypePattern/Warrior.cpp
#                src/PrototypePattern/Archer.cpp
#                src/PrototypePattern/Mage.cpp
#                src/PrototypePattern/Skill.cpp
#                )

#target_include_directories(PrototypePattern 
#                            PUBLIC
#                            ${CMAKE_CURRENT_SOURCE_DIR}/include/PrototypePattern
#                            )

# Singleton Pattern
#find_package(nlohmann_json CONFIG REQUIRED)

#add_library(SingletonPattern STATIC 
#                src/SingletonPattern/ConfigurationManager.cpp
#                src/SingletonPattern/JsonParser.cpp
#                )

#target_include_directories(SingletonPattern 
#                            PUBLIC
#                            ${CMAKE_CURRENT_SOURCE_DIR}/include/SingletonPattern
#                            )
#
#target_link_libraries(SingletonPattern PUBLIC nlohmann_json::nlohmann_json)

#add_library(BridgePattern STATIC
#                src/BridgePattern/Engine.cpp
#                src/BridgePattern/Vehicle.cpp
#                )
#target_include_directories(BridgePattern
#                            PUBLIC
#                            ${CMAKE_CURRENT_SOURCE_DIR}/include/BridgePattern
#)

#add_library(CompositePattern STATIC
#                src/CompositePattern/Building.cpp
#                src/CompositePattern/CompositeArea.cpp
#                )

#target_include_directories(CompositePattern
#                            PUBLIC
#                            ${CMAKE_CURRENT_SOURCE_DIR}/include/CompositePattern
#                            )

#add_library(DecoratorPattern STATIC
#                src/DecoratorPattern/Pizza.cpp
#                src/DecoratorPattern/PizzaDecorator.cpp
#                )

#target_include_directories(DecoratorPattern
#                            PUBLIC
#                            ${CMAKE_CURRENT_SOURCE_DIR}/include/DecoratorPattern
#                            )

#set(FactorySourceFiles 
#        src/FacadePattern/FactorySystem/ConveyorLine.cpp
#        src/FacadePattern/FactorySystem/Lighting.cpp
#        src/FacadePattern/FactorySystem/QualityControlSystem.cpp
#        src/FacadePattern/FactorySystem/RoboticManipulator.cpp
#        src/FacadePattern/FactorySystem/Ventilation.cpp
#        src/FacadePattern/FactorySystem/Warehouse.cpp        
#        )

#add_library(FacadePattern STATIC 
#                ${FactorySourceFiles}
#                src/FacadePattern/Facade.cpp
#                )

#target_include_directories(FacadePattern 
#                            PUBLIC
#                            ${CMAKE_CURRENT_SOURCE_DIR}/include/FacadePattern
#                            ${CMAKE_CURRENT_SOURCE_DIR}/include/FacadePattern/FactorySystem
#                            )

#add_library(FlyWeightPattern STATIC
#                src/FlyWeightPattern/Animation.cpp
#                src/FlyWeightPattern/Sprite.cpp
#                src/FlyWeightPattern/Texture.cpp
#                src/FlyWeightPattern/TextureFactory.cpp
#                )

#target_include_directories(FlyWeightPattern
#                            PUBLIC
#                            ${CMAKE_CURRENT_SOURCE_DIR}/include/FlyWeightPattern
#                            )

#find_package(spdlog CONFIG REQUIRED)

#add_library(ProxyPattern STATIC
#                src/ProxyPattern/RealVideoService.cpp
#                src/ProxyPattern/ProxyVideoService.cpp
#                src/ProxyPattern/User.cpp
#                )

#target_include_directories(ProxyPattern
#                            PUBLIC
#                            ${CMAKE_CURRENT_SOURCE_DIR}/include/ProxyPattern
#                            )
#target_link_libraries(ProxyPattern PUBLIC spdlog::spdlog)

#ChainOfResponsibility
#add_library(ChainOfResponsibility INTERFACE)
#target_include_directories(ChainOfResponsibility INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/ChainOfResponsibility)

#CommandPattern
#add_library(CommandPattern INTERFACE)
#target_include_directories(CommandPattern INTERFACE 
#                        ${CMAKE_CURRENT_SOURCE_DIR}/include/CommandPattern
#                        ${CMAKE_CURRENT_SOURCE_DIR}/include/CommandPattern/Receivers
#                        ${CMAKE_CURRENT_SOURCE_DIR}/include/CommandPattern/Commands
#                       )


add_library(IteratorPattern INTERFACE)
target_include_directories(IteratorPattern INTERFACE
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/IteratorPattern
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/IteratorPattern/Iterator
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/IteratorPattern/Collections
                    )

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC IteratorPattern)  
# AdapterPattern/AbstractFactory/BuilderPattern/FactoryMethod/PrototypePattern/SingletonPattern/BridgePattern/CompositePattern/DecoratorPattern/FacadePattern/FlyWeightPattern/ProxyPattern/ChainOfResponsibility/CommandPattern/CommandPattern

