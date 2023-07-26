/**
 * animals.cpp - Constructors and methods definitions for concrete classes :
 *	- Oiseaux
 *	- Lion
 *	- Elephant
 */

#include <iostream>
#include <string>
#include <vector>

#include "animal.h"

Oiseaux::Oiseaux(const std::string _name,int _legsAmount, bool _isFlying): Animal(_name, _legsAmount, _isFlying){}
void Oiseaux::scream(){
	std::cout << "Cuicui" << std::endl;
}

void Oiseaux::displayInfo(){
    std::cout << name << " have " << legsAmount << " legs and can fly ? : " << isFlying << std::boolalpha << std::endl;
}

Lion::Lion(const std::string _name, int _legsAmount, bool _isFlying , bool presenceNipple, bool presenceFur ): Animal(_name, _legsAmount , _isFlying ), Mammifere(presenceNipple,presenceFur)
{
	
}


void Lion::scream(){
	std::cout << "Je rugis " << std::endl;
}

void Lion::displayInfo(){
    std::cout << "The Lion called " << name << " have " << legsAmount 
              << " legs and has nipples ? : " << m_presenceNipple << " and have a fur ? " << m_presenceFur << std::boolalpha << std::endl; 
}

// Here we tried a subtility to make flying the elephant 
// by changing the constructor signature (as the oppsitite of other animals)
Elephant::Elephant(const std::string _name, bool _isFlying): Animal(_name, 4 ,_isFlying),Mammifere(true,true)
{

}
void Elephant::scream(){
	std::cout << "Je barrie" << std::endl;
}

void Elephant::displayInfo(){
    std::cout << "Elephant called " << name << " has " << legsAmount 
              << " legs and can fly ? " << isFlying << std::boolalpha << std::endl;
}

