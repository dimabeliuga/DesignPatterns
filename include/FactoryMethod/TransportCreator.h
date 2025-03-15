#ifndef TRANSPORT_CREATOR_H
#define TRANSPORT_CREATOR_H

#include "Transport.h"
#include <memory>

class TransportCreator {
    public:
        virtual std::unique_ptr<Transport> getTransport() = 0;
        virtual ~TransportCreator() = default;
};

class CarCreator : public TransportCreator {
    public:
        std::unique_ptr<Transport> getTransport() override;
};

class TrainCreator : public TransportCreator {
    public:
        std::unique_ptr<Transport> getTransport() override;
};

class AirplaneCreator : public TransportCreator {
    public:
        std::unique_ptr<Transport> getTransport() override;
};

class ShipCreator : public TransportCreator {
    public:
        std::unique_ptr<Transport> getTransport() override;
};


#endif //TRANSPORT_CREATOR_H