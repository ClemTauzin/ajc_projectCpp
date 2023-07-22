#include <iostream>
#include <string>

#include "Restaurant.h"

Restaurant::Restaurant(const std::string _name, int _hOpen, int _hClose, int _stars) : Shop(_name, _hOpen, _hClose), stars(_stars){}

void Restaurant::displayInfo() {
    std::cout<< name << "\n" << "Horaires d'ouvertures : "<< hOpen << "h - "<< hClose << "h\n"<< "Restaurant "<< stars <<" étoiles." << std::endl;
}


void Restaurant::addConsumable(Consumable* consumable)
{
    consumableList.push_back(consumable);
}


void Restaurant::displayMenus()
{
    std::cout << "Our restaurant can propose : ";
    for (auto& c : consumableList) c->displayInfo();
}
