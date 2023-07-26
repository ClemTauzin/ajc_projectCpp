/**
 * animal.h 
 *
 * Contains declaration and definition of abstract class Animal
 * Contains declaration and definition of class Mammifere
 * Contains declaration of  class oiseaux (inherited from Animal)
 * Contains declaration of class Lion (multiple inheritance from Animal and Mammifere
 * Contains declaration of class Elephant (multiple inheritance from Animal and Mammifere)
 *
 * See animal.cpp for definition of constructors and methods for classes
 * Oiseaux, Lion, Elephant
 */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <vector>

/**
 * Animal - Abstract class - Pure virtual class 
 */
class Animal {
    
    protected:
        std::string name;
        int legsAmount;
        bool isFlying;
    public:
        Animal(const std::string _name, int _legsAmount, bool _isFlying):name(_name), legsAmount(_legsAmount), isFlying(_isFlying){}
        virtual void scream() = 0; 
        virtual void displayInfo() = 0;
};

/**
 * Class Mammifere - Class used for Mutliple inheritance for Lion and Elephant
 */
class Mammifere{
    public:
	Mammifere(bool presenceNipple, bool presenceFur):
		m_presenceNipple(presenceNipple), m_presenceFur(presenceFur){}
        
    bool getNippleInfo() const{
	return m_presenceNipple;
    }

    protected :
	bool m_presenceNipple;
        bool m_presenceFur;
};


/**
 * class Oiseaux - Concerte inherited class from Animal
 * see animal.cpp for constructor and method definition
 */
class Oiseaux : public Animal{
    public:
        Oiseaux(const std::string _name, int legsAmount, bool isFlying);
        void scream();
        void displayInfo();
};
/**
 * Class Lion - Concrete inherited class from Animal and Mammifere
 * See animal.cpp for constructor and method definition
 */
class Lion : public Animal, public Mammifere{
    public:
        Lion(const std::string _name, int _legsAmount , bool _isFlying, bool presenceNipple, bool presenceFur);
        void scream();
	void displayInfo();
};

/**
 * Class Elephant - Concrete inherited class from Animal and Mammifere
 * See animal.cpp for constructor and method definition 
 */
class Elephant : public Animal, public Mammifere{
    public:
        Elephant(const std::string _name, bool _isFlying);
        void scream();
	void displayInfo();
};

#endif
