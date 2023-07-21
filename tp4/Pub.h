#ifndef PUB_H
#define PUB_H

#include <iostream>
#include <string>

#include "Shop.h"

class Pub : public Shop {
    private:
        int stars;
    public:
        Pub(const std::string _name, int _hOpen, int _hClose);

        void displayInfo() override; 

};
#endif