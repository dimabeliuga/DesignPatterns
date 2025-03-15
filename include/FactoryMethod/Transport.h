#ifndef TRANSPORT_H
#define TRANSPORT_H

class Transport {
    protected:
        double baseRate;
        double ratePerKm;
        double ratePerKg;
    public:
        Transport(double _baseRate, double _ratePerKm, double _ratePerKg);
        virtual void outputTransportInformation() const = 0;
        virtual void outputTransportType()        const = 0;
        virtual double calculateDeliveryPrice(double distance, double cargoWeight);
        virtual ~Transport() = default;
};

class Car : public Transport {
    public:
        Car() : Transport(100.00, 0.5, 0.1) {}
        void outputTransportInformation() const override;
        void outputTransportType() const override;
};

class Train : public Transport {
    public:
        Train() : Transport(200, 0.3, 0.2) {}
        void outputTransportInformation() const override;
        void outputTransportType() const override;
};

class Airplane : public Transport {
    public:
        Airplane() : Transport(500, 0.1, 0.5) {}
        void outputTransportInformation() const override;
        void outputTransportType() const override;
};

class Ship : public Transport {
    public:
        Ship() : Transport(300, 0.2, 0.3) {}
        void outputTransportInformation() const override;
        void outputTransportType() const override;
};



#endif //TRANSPORT_H
