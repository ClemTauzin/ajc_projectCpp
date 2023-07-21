#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>

#include "Shop.h"

class Restaurant : public Shop {
    private:
        int stars;
    public:
        Restaurant(const std::string _name, int _hOpen, int _hClose, int _stars);

        void displayInfo() override; 

};
#endif