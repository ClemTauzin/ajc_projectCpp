#include "Food.h"

#include <iostream>


Food::Food(std::string name, std::string ingredient): Consumable(name, ingredient) { PRINT_FUNC }

Food::~Food() { PRINT_FUNC }

void Food::displayInfo() const
{
	std::cout << "Meal name : " << m_Name;
	std::cout << " => Ingredients : " << m_Ingredients << std::endl;
}


