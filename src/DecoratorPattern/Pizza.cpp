#include "Pizza.h"
#include <iostream>
#include <cassert>

void Pizza::increasePrice(double price) {
    assert(price > 0);
    pricePerPiece += price;
}

Pizza::Pizza(std::string_view _name, size_t _timeToCook, double _pricePerPiece)
    : name(_name), timeToCook(_timeToCook), pricePerPiece(_pricePerPiece) {
    assert(_pricePerPiece > 0);
}

double Pizza::getPrice() const {
    return pricePerPiece;
}

const std::string& Pizza::getName() const {
    return name;
}

void Pizza::rateOrPizza(size_t grade, std::string_view review) {
    switch (grade) {
    case 1:
    case 2:
        std::cout << "We are sorry that you didn't like our service. We will take your feedback into account to improve our service" << std::endl;
        break;
    case 3:
        std::cout << "Thank you for your feedback; it is very valuable to us." << std::endl;
        break;
    case 4:
    case 5:
        std::cout << "Thank you for rating us so highly; we truly appreciate it. :)" << std::endl;
        break;
    default:
        std::cout << "Thank you for your feedback" << std::endl;
        break;
    }
}

void Margherita::getDescription() const {
    std::cout << "Margherita pizza is a typical Neapolitan pizza, made with only tomato, mozzarella cheese, fresh basil, extra-virgin olive oil, and sea salt." << std::endl;
}

void Pepperoni::getDescription() const {
    std::cout << "Pepperoni pizza is a pizza topped with pieces of pepperoni, a spicy Italian-American variety of salami." << std::endl;
}

void Neapolitan::getDescription() const {
    std::cout << "Neapolitan pizza is a style of pizza made with tomatoes and mozzarella cheese." << std::endl;
}