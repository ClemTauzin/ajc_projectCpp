/**
 * @brief cpp practice exercice 
 * @authors Clement Tauzin Olivier Wafflard
 * @date 2023/07/25
 *
 * The aim of this exercice is to pprarctive aboute several notions in C++
 * such as
 *  - polymorphism
 *  - inheritance and multiple inheritance
 *  - work on a separate file (here animals.h and animals.cpp)
 *	in that purpose, we have a #ifndef ANIMALS_H #define ANIMALS_H #endif
 *  - pratice std::vector add from abstract type, call the virtual overrid method displayInfo to see animals information
 *  - add a test on a #define to avoid filling the vector of animals in zoo 
 *
 * To Compile : in the same folder as every file as known :
 *	- main.cpp
 *	- animals.h
 *	- animals.cpp
 *
 * To compile, enter the following command : g++ -std=c++11 *.cpp
 * To execute, enter the following command : ./a.out
 *
 * test on Mac OSX : Mojave 10.14.6
 */


#include <iostream>
#include <string>
#include <vector>

#include "animal.h"

#define MAX_NBANIMALS 5


/**
 $ @brief Class Zoo : container for Animals
 */
class Zoo{
    //! private attribute : vector of abstract Animals$ class 
    std::vector<Animal*> animalList;

    public :
	//! defalut constructor
	Zoo(){} 

	//! destructor
	~Zoo(){
	    for(auto& a : animalList) delete(a);
	    animalList.clear();
	}

	//! Add an ANimal in the container : limited with #define MAX_NBANIMALS
        void addAnimal(Animal* animal){
	    if(animalList.size() < MAX_NBANIMALS)
		animalList.push_back(animal);
	    else
		std::cout << "Cannot add another animal : the zoo is full ; maximum number of animals : " << MAX_NBANIMALS << std::endl;
	}

   	//! Display Animals information from the overrid displayInfo for each concrete 
	//  inherited class from Animals
        void displayAnimalsInfo(){
		for(auto& a : animalList){
		    a->displayInfo();
		}
	}
};


/**
 **********************************************
 * 	MAIN : first input of the program     *
 **********************************************
 */
int main(){

    // Instanciate different kinds of animals
    Oiseaux* goeland = new Oiseaux("Jose",2,true); 
    Lion* lion = new Lion("Leo",4,false,true,true);
    Animal* elephant1 = new Elephant("Dumbo",true);

    // Not only with pointer and new keyword : RAII	
    Elephant elephant2("Joe the elephant",false);
    Oiseaux eagle("eagle",2,true);
    Lion symba("symba",4,false,true,false); 
    
    // First test wwithout the class Zoo : only with a vector
    // std::vector<Animal*> zoo;
    // zoo.push_back(goeland);
    // zoo.push_back(lion);
    // zoo.push_back(elephant);

    // Object zoo instantiation
    Zoo zoo;

    // add each animals in the zoo
    zoo.addAnimal(goeland);
    zoo.addAnimal(lion);
    zoo.addAnimal(elephant1);
    zoo.addAnimal(&elephant2);
    zoo.addAnimal(&symba);
    zoo.addAnimal(&eagle);

    // Old test with the vector instead of the Zoo class
    // for(auto& a : zoo){
    //	a->scream();
    // }

    // display all animals information
    zoo.displayAnimalsInfo();

    // Memory desallocation (only for new using)
    delete(static_cast<Elephant*>(elephant1));
    delete(lion);
    delete(goeland);
    return 0;
}
