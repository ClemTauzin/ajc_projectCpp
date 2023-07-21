#include "Drink.h"
#include <iostream>

Drink::Drink(std::string name) : Consumable(name){ PRINT_FUNC }
Drink::Drink(int quantity) : Consumable(quantity) { PRINT_FUNC }
Drink::Drink(std::string name, int quantity) : Consumable(name,quantity) { PRINT_FUNC }

Drink::~Drink(){ PRINT_FUNC }

void Drink::displayInfo() const
{
	std::cout << "Drink name : " << m_Name << " | quantity : " << m_Quantity << std::endl;
}