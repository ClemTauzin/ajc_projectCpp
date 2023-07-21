#pragma once
#include "Consumable.h"


class Drink : public Consumable

{
public:
    Drink(std::string name);
    explicit Drink(int quantity);
    Drink(std::string name, int quantity);

    ~Drink();

    void displayInfo() const;
};

