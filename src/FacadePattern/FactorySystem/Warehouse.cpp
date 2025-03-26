#include "Warehouse.h"

#include <iostream>
#include <random>

Warehouse::Warehouse()
{
    std::cout << "Warehouse is created." << std::endl;
}

void Warehouse::checkSavings(std::string item)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 200);
    std::cout << "There are " << dis(gen) << " " << item << " in the warehouse." << std::endl;
}

void Warehouse::orderItem(std::string item, size_t quantity)
{
    std::cout << "Ordered " << quantity << " " << item << " from the supplier." << std::endl;
}

void Warehouse::deliverOnConveyorLine(std::string item, size_t quantity)
{
    std::cout << "Delivered " << quantity << " " << item << " on the conveyor line." << std::endl;
}
