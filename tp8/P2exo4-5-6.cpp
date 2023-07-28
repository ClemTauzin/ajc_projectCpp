#include <iostream>
#include <string>
#include <vector>


class Ressource{
    private:
    std::string name;
    int age;
    public:
    Ressource(const std::string& _name, int _age): name(_name), age(_age){};

    // Constructeur de mouvement
    // 1 seule & -> constructeur par copie
    // && -> constructeur par mouvement
    // Transfère les infos à l'objet créé
    // commande : NomDeClass objetNonExistant = std::move(objetExistant);
    Ressource(Ressource&& other): name(other.name), age(other.age){
        other.name = "";
        other.age = 0;
    }

    // Constructeur de copie
    Ressource(const Ressource &other) : name(other.name), age(other.age){}


    // Opérateur d'affectation de mouvement
    // Permet de modifier les informations d'un objet déjà existant
    // commande : objetExistant2 = std::move(objetExistant1);
    Ressource& operator=(Ressource&& other){
        if (this != &other){
        // + Libérer la mémoire existante si nécessaire
        name = other.name;
        age = other.age;
        other.name = "";
        other.age = 0;
        }
        return *this;
    }

    std::string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    ~Ressource(){};
};


class Container{
    private:
    std::vector<Ressource*> ressources;
    public:
    void addRessource(Ressource* ressource){
        ressources.push_back(ressource);
    };
};


int main(){
    // exercice 1 :
Ressource exemple1("exemple1", 1);
Ressource exemple2("exemple2", 2);
Ressource exemple3 = std::move(exemple2);

std::cout<<exemple1.getName()<<std::endl;
std::cout<<exemple2.getName()<<std::endl;
std::cout<<exemple3.getName()<<std::endl;

// exercice 2 :
Ressource exemple4("exemple4", 4);
Ressource exemple5("exemple5", 5);

std::cout<<exemple4.getName()<<std::endl;
std::cout<<exemple5.getName()<<std::endl;

exemple5 = std::move(exemple4);
std::cout<<"\n"<<exemple4.getName()<<std::endl;
std::cout<<exemple5.getName()<<std::endl;

return 0;
}