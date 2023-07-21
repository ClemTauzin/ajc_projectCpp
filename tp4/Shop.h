#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>

class Shop {
    protected:
        std::string name;
        int hOpen;
        int hClose;
    public:
        Shop(const std::string _name, int _hOpen, int _hClose) : name(_name), hOpen(_hOpen), hClose(_hClose){}

        virtual void displayInfo() = 0 ; 
};
#endif // SHOP_h