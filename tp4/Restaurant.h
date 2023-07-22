#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include <vector>
// #include "Drink.h"
// #include "Food.h"
#include "Shop.h"
#include "Consumable.h"

class Restaurant : public Shop {

    // std::vector<Food*> foodList;
    // std::vector<Drink*> drinkList;

    std::vector<Consumable*> consumableList;

    private:
        int stars;
    public:
        Restaurant(const std::string _name, int _hOpen, int _hClose, int _stars);

        void displayInfo() override; 
        void addConsumable(Consumable* consumable);
        void displayMenus();
};
#endif