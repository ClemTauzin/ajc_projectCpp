#include <iostream>
#include <string>
#include <vector>


class Shop {
    protected:
        std::string name;
        std::string city;
        int hOpen;
        int hClose;
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


class LetsGoOut{
        private:
            std::vector<Shop*> Shop;
            std::vector<Consumable*> Consumable;
        public:
            void addShop(Shop* shop){
                Shop.push_back(shop);
            }
            void addConsumable(Consumable* consumable){
                Consumable.push_back(consumable);
            }
            void diplayAllInfo(){
                for (int i = 0; i < Shop.size(); i++)
                {
                    Shop[i]->displayInfo();
                    Consumable[i]->displayInfo();
                }
            }
                        void diplayInfo(){
                for (int i = 0; i < Shop.size(); i++)
                {
                    Shop[i]->displayInfo();
                    Consumable[i]->displayInfo();
                }
            }

        ~LetsGoOut(){
            std::cout<<"Mémoire LetsGoOut effacée"<<std::endl;
        };
};


int main() {
Restaurant restaurant1("Les Délices d'Orient", "Toulouse", 12, 14, 2);
Pub pub1("A la bonne Fourchette", "Albi", 18, 23);

restaurant1.displayInfo();
pub1.displayInfo();

return 0;
};