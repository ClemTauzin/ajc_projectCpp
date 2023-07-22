#include "Drink.h"
#include <iostream>


Drink::Drink(std::string name, std::string ingredient) : Consumable(name, ingredient) { PRINT_FUNC }

Drink::~Drink(){ PRINT_FUNC }

void Drink::displayInfo() const
{
	std::cout << "Drink name : " << m_Name ;
	std::cout << " => Ingredients : " << m_Ingredients << std::endl;
}