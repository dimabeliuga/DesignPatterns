#ifndef PIZZA_DECORATOR_H
#define PIZZA_DECORATOR_H

#include "Pizza.h"
#include <memory>

class PizzaDecorator : public Pizza {
protected:
    std::unique_ptr<Pizza> pizza;
public:
    PizzaDecorator(std::unique_ptr<Pizza> _pizza);
    void getDescription() const override;
    double getPrice() const override = 0;
};

class ExtraCheese : public PizzaDecorator {
public:
    explicit ExtraCheese(std::unique_ptr<Pizza> _pizza);
    void getDescription() const override;
    double getPrice() const override;
};

class Mushrooms : public PizzaDecorator {
public:
    explicit Mushrooms(std::unique_ptr<Pizza> _pizza);
    void getDescription() const override;
    double getPrice() const override;
};

class Olives : public PizzaDecorator {
public:
    explicit Olives(std::unique_ptr<Pizza> _pizza);
    void getDescription() const override;
    double getPrice() const override;
};

#endif // PIZZA_DECORATOR_H