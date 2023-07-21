#include "Food.h"

#include <iostream>

Food::Food(std::string name) : Consumable(name) { PRINT_FUNC }
Food::Food(int quantity) : Consumable(quantity) { PRINT_FUNC }
Food::Food(std::string name, int quantity) : Consumable(name, quantity) { PRINT_FUNC }

Food::~Food() { PRINT_FUNC }

void Food::displayInfo() const
{
	std::cout << "Food name : " << m_Name << " | quantity : " << m_Quantity << std::endl;
}