#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>

class Warehouse {
    public:
        Warehouse();
        void checkSavings(std::string item);
        void orderItem(std::string item, size_t quantity);
        void deliverOnConveyorLine(std::string item, size_t quantity);
};

#endif // WAREHOUSE_H