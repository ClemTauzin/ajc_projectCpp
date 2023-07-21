#pragma once
#include "Consumable.h"




class Food :public Consumable

{


public:
    Food(std::string name);
    explicit Food(int quantity);
    Food(std::string name, int quantity);

    ~Food();

    void displayInfo() override const;
};