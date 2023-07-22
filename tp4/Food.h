#pragma once
#include "Consumable.h"

class Food : public Consumable
{    

public:

    Food(std::string name, std::string ingredient);

    ~Food();

    void displayInfo() const override;
};