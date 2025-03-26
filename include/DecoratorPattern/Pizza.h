#ifndef PIZZA_H
#define PIZZA_H

#include <string>

class Pizza {
protected:
    std::string name;
    size_t timeToCook;
    double pricePerPiece;

    void increasePrice(double price);
public:
    Pizza() = default;
    Pizza(std::string_view _name, size_t _timeToCook, double _pricePerPiece);

    virtual void getDescription() const = 0;
    virtual double getPrice() const;  // Виртуальный метод, возвращает double

    const std::string& getName() const;
    void rateOrPizza(size_t grade, std::string_view review = "");  // Оставлен как есть
};

class Margherita : public Pizza {
public:
    Margherita() : Pizza("Margherita", 15, 9.87) {}
    void getDescription() const override;
};

class Pepperoni : public Pizza {
public:
    Pepperoni() : Pizza("Pepperoni", 20, 12.45) {}
    void getDescription() const override;
};

class Neapolitan : public Pizza {
public:
    Neapolitan() : Pizza("Neapolitan", 25, 15.99) {}
    void getDescription() const override;
};

#endif // PIZZA_H