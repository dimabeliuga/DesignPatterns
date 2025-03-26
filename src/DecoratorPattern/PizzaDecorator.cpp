#include "PizzaDecorator.h"
#include <iostream>

PizzaDecorator::PizzaDecorator(std::unique_ptr<Pizza> _pizza)
    : pizza(std::move(_pizza)) {}

void PizzaDecorator::getDescription() const {
    pizza->getDescription();
}

ExtraCheese::ExtraCheese(std::unique_ptr<Pizza> _pizza)
    : PizzaDecorator(std::move(_pizza)) {}

void ExtraCheese::getDescription() const {
    pizza->getDescription();
    std::cout << "Extra cheese was added to the pizza." << std::endl;
}

double ExtraCheese::getPrice() const {
    return pizza->getPrice() + 2.5;
}

Mushrooms::Mushrooms(std::unique_ptr<Pizza> _pizza)
    : PizzaDecorator(std::move(_pizza)) {}

void Mushrooms::getDescription() const {
    pizza->getDescription();
    std::cout << "Mushrooms were added to the pizza." << std::endl;
}

double Mushrooms::getPrice() const {
    return pizza->getPrice() + 3.5;
}

Olives::Olives(std::unique_ptr<Pizza> _pizza)
    : PizzaDecorator(std::move(_pizza)) {}

void Olives::getDescription() const {
    pizza->getDescription();
    std::cout << "Olives were added to the pizza." << std::endl;
}

double Olives::getPrice() const {
    return pizza->getPrice() + 1.5;
}