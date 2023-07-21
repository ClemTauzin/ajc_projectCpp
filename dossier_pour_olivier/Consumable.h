#pragma once
#include <string>
#include <vector>

// #define PRINT_FUNC std::cout << this << ":\t" << __FUNCSIG__ << std::endl;
#define PRINT_FUNC


class Consumable
{

protected:

	std::string m_Ingredients;
	std::string m_Name;

public:
	
	Consumable(std::string name, std::string ingredients) : m_Name(name), m_Ingredients(ingredients) { PRINT_FUNC }

	virtual ~Consumable(){ PRINT_FUNC }

	virtual void displayInfo() const = 0;
};

