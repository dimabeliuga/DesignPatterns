#ifndef CONCRETE_COMMANDS_H
#define CONCRETE_COMMANDS_H

#include "Command.h"
#include "Receivers.h"
#include <memory>
#include <iostream>
#include <vector>

class TurnOnLight : public Command {
    private:
        std::shared_ptr<Light> light;
    public:
        TurnOnLight(std::shared_ptr<Light> _light) : light(_light) {}
        void execute() override {
            light -> turnOn();
        }
        void undo() override {
            light -> tunrnOff();
            std::cout << "Undoing TurnOnLight command" << std::endl;
        }
        void getName() const override {
            std::cout << "TurnOnLight" << std::endl;
        }
};

class SetHeatingTemperatureCommand : public Command {
    private:
        std::shared_ptr<Heating> heating;
        uint16_t previousTemperature;
        uint16_t newTemperature;
    public:
        SetHeatingTemperatureCommand(std::shared_ptr<Heating> _heating) : heating(_heating) {}
        void execute() override {
            previousTemperature = heating -> getTemperature();
            heating -> setTemperature(newTemperature);
        }
        void undo() override {
            heating -> setTemperature(previousTemperature);
            std::cout << "Undoing SetHeatingTemperatureCommand command" << std::endl;
        }
        void getName() const override {
            std::cout << "SetHeatingTemperatureCommand" << std::endl;
        }

};


class LockDoorCommand : public Command {
    private:
        std::shared_ptr<SmartLock> smartLock;
    public:
        LockDoorCommand(std::shared_ptr<SmartLock> _lock) : smartLock(_lock) {}
        void execute() override {
            smartLock -> lock();
        }
        void undo() override {
            smartLock -> unlock();
            std::cout << "Undoing LockDoorCommand command" << std::endl;
        }
        void getName() const override {
            std::cout << "LockDoorCommand" << std::endl;
        }
};

class TurnOnTheMusic : public Command {
    private:
        std::shared_ptr<AudioSystem> audioSystem;
        uint16_t previousVolume;
        std::string previousTrack;
    public:
        TurnOnTheMusic(std::shared_ptr<AudioSystem> _audioSystem) : audioSystem(_audioSystem)
        {
            previousTrack = audioSystem ->getCurrentTrack();
            previousVolume = audioSystem -> getCurrentVolume();
        }
        void execute() override {
            audioSystem -> turnOn();
        }
        void execute(const std::string& track) {
            previousTrack = audioSystem -> getCurrentTrack();
            audioSystem -> playTrack(track);
            std::cout << "New track has been set" << std::endl;
        }
        void execute(const uint16_t volume) {
            previousVolume = audioSystem -> getCurrentVolume();
            audioSystem -> setVolume(volume);
            std::cout << "New volume has been set" << std::endl;
        }
        void execute(const std::string& track, const uint16_t volume) {
            execute(track);
            execute(volume);
            std::cout << "New track and volume have been set" << std::endl;
        }
        void getName() const override {
            std::cout << "TurnOnTheMusic Command" << std::endl;
        }
        void undo() override {
            audioSystem -> playTrack(previousTrack);
            audioSystem -> setVolume(previousVolume);
            audioSystem -> turnOff();
            std::cout << "Turning off the audioSystem" << std::endl;
        }
};

class TurnOnAirConditioner : public Command {
    private:
        std::shared_ptr<AirConditioner> airConditioner;
        uint16_t previousTemperature;
    public:
        TurnOnAirConditioner(std::shared_ptr<AirConditioner> _airConditioner)
                    : airConditioner(_airConditioner) 
            {
                previousTemperature = airConditioner -> getTemperature();
            }
        void execute() override{
            airConditioner -> turnOn();
            std::cout << "Air conditioner turned on" << std::endl;
        }
        void execute(uint16_t temperature) {
            execute();
            previousTemperature = airConditioner -> getTemperature();
            airConditioner -> setTemperature(temperature);
            std::cout << "New temperature has been set" << std::endl;
        }
        void getName() const override {
            std::cout << "TurnOnAirConditioner Command" << std::endl;
        }
        void undo() override {
            airConditioner -> turnOff();
            airConditioner -> setTemperature(previousTemperature);
            std::cout << "AirConditioner command was undid" << std::endl;
        }
        
};

class MacroCommand : public Command {
    private:
        std::vector<std::shared_ptr<Command>> commands;
    public:
        void execute() override {
            for(const auto& iter : commands) {
                iter -> execute();
            }
        }
        void getName() const override {
            for(const auto& iter : commands) {
                iter -> getName();
            }
        }
        void undo() override {
            for(const auto& iter : commands) {
                iter -> undo();
            }
        }
        void addCommand(std::shared_ptr<Command> command) {
            if(command != nullptr) {
                commands.emplace_back(command);
            }
        }
};
#endif // CONCRETE_COMMANDS_H