#include <iostream>
#include <string>

#include "Pub.h"

Pub::Pub(const std::string _name, int _hOpen, int _hClose) : Shop(_name, _hOpen, _hClose){}

void Pub::displayInfo() {
    std::cout<< name << "\n" << "Horaires d'ouvertures : "<< hOpen << "h - "<< hClose << "h" << std::endl;
}


void Pub::addDrink(Drink* drink)
{
    drinkList.push_back(drink);
}

void Pub::displayMenus()
{
    std::cout << "Our pub can propose : ";
    for (auto& d : drinkList) d->displayInfo();
}