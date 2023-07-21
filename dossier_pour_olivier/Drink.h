#pragma once
#include "Consumable.h"


class Drink : public Consumable

{
public:

    Drink(std::string name, std::string ingredient);

    ~Drink();

    void displayInfo() const override ;
};

