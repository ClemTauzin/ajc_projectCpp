#ifndef PUB_H
#define PUB_H

#include <iostream>
#include <string>
#include <vector>

#include "Drink.h"
#include "Shop.h"

class Pub : public Shop {

    std::vector<Drink*> drinkList;

    private:
        int stars;
    public:
        Pub(const std::string _name, int _hOpen, int _hClose);

        void displayInfo() override; 

        void addDrink(Drink* drink);
        void displayMenus();

};
#endif