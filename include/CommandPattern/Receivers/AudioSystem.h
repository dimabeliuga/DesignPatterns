#ifndef AUDIO_SYSTEM_H
#define AUDIO_SYSTEM_H

#include <iostream>
#include <string>

class AudioSystem {
    private:
        bool isOn = false;
        uint16_t volume = 0;
        std::string currentTrack = "No track playing";
    public:
        void turnOn() {
            isOn = true;
            std::cout << "Audio system is turned on" << std::endl;
        }
        void turnOff() {
            isOn = false;
            std::cout << "Audio system is turned off" << std::endl;
        }
        void setVolume(uint16_t volume) {
            this->volume = volume;
            std::cout << "Audio system volume is set to " << (int)volume << std::endl;
        }
        void playTrack(const std::string& track) {
            currentTrack = track;
            std::cout << "Playing track: " << currentTrack << std::endl;
        }
        void getStatus() const {
            std::cout << "Audio system is " << (isOn ? "on" : "off") << std::endl;
            std::cout << "Audio system volume is " << (int)volume << std::endl;
            std::cout << "Current track: " << currentTrack << std::endl;
        }
        void stopTrack() {
            currentTrack = "No track playing";
            std::cout << "Stopped playing track" << std::endl;
        }
        std::string getCurrentTrack() const {return currentTrack; }
        uint16_t getCurrentVolume() const { return volume; }
};

#endif // AUDIO_SYSTEM_H