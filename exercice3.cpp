#include <iostream>
#include <string>

class Animal
{
private:
    std::string espece;
    double poids;
public:
    Animal(const std::string _esp, double _pds) : espece(_esp), poids(_pds) {}

    // void animal(const std::string _esp, double _pds) {
    //     espece = _esp;
    //     poids = _pds;
    // }

    void setEspece(std::string _espece) {espece = _espece;};
    void setPoids(double _poids) {poids = _poids;};
    std::string getEspece() const {return espece;};
    double getPoids() const {return poids;};

    void afficher(){
    std::cout << "Espece de l'animal : " << espece << std::endl;
    std::cout << "Poids de l'animal (en kg): " << poids << std::endl;

}
};



int main(){
    // Animal animal1;
    // animal1.setEspece("lion");
    // animal1.setPoids(80);

    // Animal animal2;
    // animal2.setEspece("zèbre");
    // animal2.setPoids(150);

    // Animal animal3;
    // animal3.animal("chat", 8);

Animal animal1("chat", 8);
Animal animal2("lapin", 48);
Animal animal3("chien", 10);

    animal1.afficher();

    std::cout << "Espece de l'animal : " << animal2.getEspece() << std::endl;
    std::cout << "Poids de l'animal (en kg): " << animal2.getPoids() << std::endl;

    animal3.afficher();

    return 0;
}