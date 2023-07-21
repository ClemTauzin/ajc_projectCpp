#include <iostream>
#include <string>
#include <vector>

#define PRINT_FUNC



class Shop {
    protected:
        std::string name;
        std::string city;
        int hOpen;
        int hClose;
        std::vector<Consumable*> ConsumableList;
    public:
        Shop(const std::string _name, std::string _city, int _hOpen, int _hClose) : name(_name), city(_city), hOpen(_hOpen), hClose(_hClose){}

        virtual void displayInfo() = 0 ; 
};

class Restaurant : public Shop {
    private:
        int stars;
    public:
        Restaurant(const std::string _name, std::string _city, int _hOpen, int _hClose, int _stars) : Shop(_name, _city, _hOpen, _hClose), stars(_stars){}

        void displayInfo() override {
            std::cout<< name << " - "<< city << "\n" << "Horaires d'ouvertures : "<< hOpen << "h - "<< hClose << "h\n"<< "Restaurant "<< stars <<" étoiles." << std::endl;
    }
};

class Pub : public Shop {
    private:
        int stars;
    public:
        Pub(const std::string _name, std::string _city, int _hOpen, int _hClose) : Shop(_name, _city, _hOpen, _hClose){}

        void displayInfo() override {
            std::cout<< name << " - "<< city << "\n" << "Horaires d'ouvertures : "<< hOpen << "h - "<< hClose << "h" << std::endl;
        }

};

class Consumable
{
protected:
	std::string m_Name;
	std::string m_Ingredient;

public:
	Consumable(std::string name) : m_Name(name),m_Ingredient(0) { PRINT_FUNC }	
	explicit Consumable(std::string ingredient) :m_Name("unknown"), m_Ingredient(ingredient) { PRINT_FUNC }
	Consumable(std::string name, std::string ingredient) : m_Name(name), m_Ingredient(ingredient) { PRINT_FUNC }

	virtual ~Consumable(){ PRINT_FUNC }

	virtual void displayCaract() = 0;
};

class Food :public Consumable{
public:

    Food(std::string name) : Consumable(name) { PRINT_FUNC }
    Food(std::string ingredient) : Consumable(ingredient) { PRINT_FUNC }
    Food(std::string name, std::string ingredient) : Consumable(name, ingredient) { PRINT_FUNC }

    ~Food() { PRINT_FUNC }

    void displayCaract() override
    {
        std::cout << "Food name : " << m_Name << " | ingredients : " << m_Ingredient << std::endl;
    }


};

class Drink : public Consumable{
    public:
        Drink(std::string name);
        explicit Drink(std::string ingredient);
        Drink(std::string name, int quantity);

        Drink(std::string name) : Consumable(name){ PRINT_FUNC }
        Drink(std::string ingredient) : Consumable(ingredient) { PRINT_FUNC }
        Drink(std::string name, std::string ingredient) : Consumable(name,ingredient) { PRINT_FUNC }

        ~Drink(){ PRINT_FUNC }

        void displayCaract() override {
            std::cout << "Drink name : " << m_Name << " | quantity : " << m_Ingredient << std::endl;
        }
};

// class LetsGoOut{
//         private:
//             std::vector<Shop*> Shops;
//             std::vector<Consumable*> Consumables;
//         public:
//             void addShop(Shop* shop){
//                 Shop.push_back(shop);
//             }
//             void addConsumable(Consumable* consumable){
//                 Consumable.push_back(consumable);
//             }
//             void diplayAllInfo(){
//                 for (int i = 0; i < Shop.size(); i++)
//                 {
//                     Shop[i]->displayInfo();
//                     Consumable[i]->displayInfo();
//                 }
//             }


//         ~LetsGoOut(){
//             std::cout<<"Mémoire LetsGoOut effacée"<<std::endl;
//         };
// };


int main() {
Restaurant restaurant1("Les Délices d'Orient", "Toulouse", 12, 14, 2);
Pub pub1("A la bonne Fourchette", "Albi", 18, 23);

restaurant1.displayInfo();
pub1.displayInfo();

return 0;
};