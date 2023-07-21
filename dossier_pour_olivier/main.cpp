#include <iostream>

// #include "Consumable.h"
#include "Drink.h"
#include "Food.h"
#include "Pub.h"
#include "Restaurant.h"




int main() {

	Restaurant resto1("A la bonne crepe", 10, 20, 1);
	Pub bistro1("Chez Dede", 6, 18);

	Food food1("Kouign Aman", "Du beurre du beurre et du beurre");
	Food food2("Crepe Ble noir", "Du ble noir des oeufs de l'eau et... du beurre");

	Drink drink1("eau", "eau du Ponant");
	Drink drink2("cidre", "de la pomme et de l'amour");
	Drink drink3("vin blanc", "du raisin");
	
	resto1.addConsumable(&food1);
	resto1.addConsumable(&drink1);
	bistro1.addDrink(&drink2);

	resto1.displayInfo();
	resto1.displayMenus();


	bistro1.displayInfo();
	bistro1.displayMenus();



	return 0;
}