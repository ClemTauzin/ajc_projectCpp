#include <iostream>
#include <string>
// Classe représentant une personne
class Personne {
private:
 std::string nom; // Attribut privé : nom de la personne
 int age; // Attribut privé : âge de la personne
public:
 // Méthodes publiques pour accéder et modifier les attributs encapsulés
 void setNom(const std::string& _nom) { nom = _nom; }
 void setAge(int _age) { age = _age; }
 std::string getNom() const { return nom; }
 int getAge() const { return age; }
};


class Etudiant : public Personne {
private:
    std::string school_name;
public:
 void setEcole(std::string _school_name) { school_name = _school_name; }
 std::string getEcole() const { return school_name; }
};


int main() {
 Personne personne; // Création d'un objet de type Personne
 // Utilisation des méthodes pour accéder et modifier les attributs encapsulés
 personne.setNom("John Doe");
 personne.setAge(30);
 // Affichage des attributs encapsulés
 std::cout << "Nom : " << personne.getNom() << ", Age : " << personne.getAge() << std::endl;

 Etudiant etudiant1; // Création d'un objet de type Employe
 // Utilisation des méthodes pour accéder et modifier les attributs encapsulés de la classe Etudiant
 etudiant1.setNom("Jane Smith");
 etudiant1.setAge(25);
 etudiant1.setEcole("Ecole St Exupere");
 // Affichage des attributs encapsulés de la classe Employe
 std::cout << "Nom : " << etudiant1.getNom() << ", Age : " << etudiant1.getAge()
 << ", Numéro d'employé : " << etudiant1.getEcole() << std::endl;
 return 0;
}
