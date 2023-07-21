
#include <iostream>
#include <string>


// création de la classe Personne avec des attributs string nom, int age et string profession en private
class Personne {
private:
    std::string nom;     
    int age;               
    std::string profession;  

public:
    // Constructeur par défaut
    Personne() {
        nom = "";            
        age = 0;           
        profession = "";     
    }

    // Constructeur multiple prenant un nom et un âge en paramètres
    Personne(const std::string& n, int a) {
        nom = n;            
        age = a;             
        profession = "";     
    }

    // Constructeur de copie
    Personne(const Personne& autre) {
        nom = autre.nom;    
        age = autre.age;    
        profession = autre.profession; 
    }

//   constructeur explicit indicant qu'il ne prend que des int pour l'age ?
    explicit Personne(int a) {
        nom = "";            
        age = a;             
        profession = "";     
    }

 //   constructeur explicit indicant qu'il ne prend que des string pour le nom ?
    explicit Personne(const std::string& n) {
        nom = n;             
        age = 0;             
        profession = "";     
    }

// Constructeur multiple avec le nom, l'age et la profession
    Personne(const std::string& n, int a, const std::string& p) : nom(n), age(a), profession(p) {
 
    }

// fonction afficherDetail qui reprend les informations de l'objet et les affiche
    void afficherDetails() {
        std::cout << "Les détails de la personne" << std::endl;
        std::cout << "Nom : " << nom << std::endl;
        std::cout << "Âge : " << age << std::endl;
        std::cout << "Profession : " << profession << std::endl;
    }
};

int main() {
    // Exemples d'utilisation des constructeurs

    // Utilisation du constructeur simple pour créer l'objet personne1 appartenant à la classe Personne et afficher ses détails
    Personne personne1;                       
    personne1.afficherDetails();

    // Utilisation du constructeur multiple créer personne2 appartenant à la classe Personne et pour renseigner le nom et l'age de l'objet personne2 et afficher ses détails
    Personne personne2("Alice", 25);            
    personne2.afficherDetails();

    // Utilisation du constructeur copie créer personne3 appartenant à la classe Personne et copier les infos de personne2 et afficher ses détails
    Personne personne3 = personne2;            
    personne3.afficherDetails();

    // Utilisation du constructeur explicit créer personne4 appartenant à la classe Personne et avec son age au format int et afficher ses détails
    Personne personne4(30);                    
    personne4.afficherDetails();

    // Utilisation du constructeur explicit créer personne5 appartenant à la classe Personne et avec son nom au format string et afficher ses détails
    Personne personne5("Bob");                    
  personne5.afficherDetails();

    // Utilisation du constructeur multiple créer personne6 appartenant à la classe Personne et renseigner son nom, son age et sa profession et afficher ses détails
    Personne personne6("Charlie", 35, "Ingénieur");  // 
    personne6.afficherDetails();

    return 0;
}