#pragma once
#include <string>

// #define PRINT_FUNC std::cout << this << ":\t" << __FUNCSIG__ << std::endl;
#define PRINT_FUNC

class Consumable
{
protected:
	std::string m_Name;
	int m_Quantity;

public:
	Consumable(std::string name) : m_Name(name),m_Quantity(0) { PRINT_FUNC }	
	explicit Consumable(int quantity) :m_Name("unknown"), m_Quantity(quantity) { PRINT_FUNC }
	Consumable(std::string name, int quantity) : m_Name(name), m_Quantity(quantity) { PRINT_FUNC }

	virtual ~Consumable(){ PRINT_FUNC }

	virtual void displayInfo() = 0;
};

