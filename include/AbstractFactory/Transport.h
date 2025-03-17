#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "Desctiption.h"
#include <iostream>

class Transport {
    public:
        virtual void describe() const = 0;
        virtual ~Transport() = default;
};

class FantasyWorldTransport : public Transport {
    public:
        void describe() const override {
            std::cout << "\nFantasy World transport:\n" << Desctiptions::Transport::fantasyTransport << "\n\n";
        }
        ~FantasyWorldTransport() = default;
};

class AncientWorldTransport : public Transport {
    public:
        void describe() const override {
            std::cout << "\nAncient World transport: \n" << Desctiptions::Transport::ancientTransport << "\n\n";
        }
        ~AncientWorldTransport() = default;
};

class SpaceWorldTransport : public Transport {
    public:
        void describe() const override {
            std::cout << "\nSpace World transport: \n" << Desctiptions::Transport::spaceTransport << "\n\n";
        }
        ~SpaceWorldTransport() = default;
};

#endif //TRANSPORT_H
