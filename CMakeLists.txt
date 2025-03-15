cmake_minimum_required(VERSION 3.20)
project(DesignPatterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
add_library(FactoryMethod STATIC 
                src/FactoryMethod/Transport.cpp
                src/FactoryMethod/TransportCreator.cpp
                src/FactoryMethod/CargoCreator.cpp
                )
target_include_directories(FactoryMethod 
                            PUBLIC 
                            ${CMAKE_CURRENT_SOURCE_DIR}/include/FactoryMethod)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC FactoryMethod)  # AdapterPattern/AbstractFactory/BuilderPattern