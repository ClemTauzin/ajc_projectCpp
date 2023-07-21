
// Clément Tauzin
#include <iostream>
#include <string>

// création de la classe Personne
class Personne {
    
public:

// creation fonction pour afficher les un texte sur les détails de la personne
    void afficherDetails() {
        std::cout << "Les détails de la personne" << std::endl;
    }

// initialisation de la fonction modifierAge qui prend comme argument un entier avec comme valeur par défaut 0
    void modifierAge(int age = 0) {
      
    }

// initialisation de la fonction modifierNom qui prend comme argument un string
    void modifierNom(const std::string& nom) {

    }
};

// création de la classe dérivée Etudiant qui prend les méthodes public de Personne
class Etudiant : public Personne {
public:

// surcharge -> reaffectation de la fonction afficherDetails pour donner les détails de l'étudiant
    void afficherDetails() {
        std::cout << "Les détails de l'étudiant" << std::endl;
    }
};

int main() {
//   initialisation de l'objet personne appartenant à la classe Personne
    Personne personne;
    // activation de la afficherDetails pour l'objet personne
    personne.afficherDetails();
    // activation de la fonction modifierAge pour l'objet personne
    personne.modifierAge(25); 
    // activation de la fonction modifierNom pour l'objet personne
    personne.modifierNom("Alice"); 
    // Création d'un objet étudiant appartenant à la classe Etudiant
    Etudiant etudiant;
    // activation de la afficherDetails pour l'objet etudiqnt
    etudiant.afficherDetails(); 
    // activation de la fonction modifierNom pour l'objet etudiant
    etudiant.modifierAge(20); 
    // activation de la fonction modifierNom pour l'objet etudiant
    etudiant.modifierNom("Bob"); 
    return 0;
}
// La classe Personne est définie avec trois attributs privés :
// nom : Représente le nom de la personne.
// age : Représente l'âge de la personne.
// profession : Représente la profession de la personne.
// Les constructeurs sont définis pour initialiser les attributs de la classe :
// Constructeur par défaut : Initialise les attributs avec des valeurs par défaut.
// Constructeur prenant un nom et un âge en paramètres : Affecte les valeurs fournies aux attributs nom et age.
// Constructeur de copie : Copie les valeurs des attributs depuis un autre objet de type Personne.
// Constructeur prenant un entier en paramètre : Affecte la valeur fournie à l'attribut age.
// Constructeur prenant une chaîne de caractères en paramètre : Affecte la valeur fournie à l'attribut nom.
// Constructeur à arguments multiples : Initialise les attributs avec les valeurs fournies en paramètres.
// La méthode afficherDetails() affiche les détails de la personne en utilisant les attributs nom, age et profession.
// Dans la fonction main(), des objets de type Personne sont créés en utilisant différents constructeurs :
// personne1 : Utilise le constructeur par défaut.
// personne2 : Utilise le constructeur prenant un nom et un âge.
// personne3 : Utilise le constructeur de copie en utilisant personne2 comme objet source.
// personne4 : Utilise le constructeur prenant un entier.
// personne5 : Utilise le constructeur prenant une chaîne de caractères.
// personne6 : Utilise le constructeur à arguments multiples.
// Pour chaque objet personne, la méthode afficherDetails() est appelée pour afficher les détails correspondants.
// Ainsi, le programme démontre l'utilisation des différents constructeurs de la classe Personne et la méthode pour afficher les détails d'une personne.

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
// Explication :
// La classe Personne est définie avec trois attributs privés :
// nom : Représente le nom de la personne.
// age : Représente l'âge de la personne.
// profession : Représente la profession de la personne.
// Les constructeurs sont définis pour initialiser les attributs de la classe :
// Constructeur par défaut : Initialise les attributs avec des valeurs par défaut.
// Constructeur prenant un nom et un âge en paramètres : Affecte les valeurs fournies aux attributs nom et age.
// Constructeur de copie : Copie les valeurs des attributs depuis un autre objet de type Personne.
// Constructeur prenant un entier en paramètre : Affecte la valeur fournie à l'attribut age.
// Constructeur prenant une chaîne de caractères en paramètre : Affecte la valeur fournie à l'attribut nom.
// Constructeur à arguments multiples : Initialise les attributs avec les valeurs fournies en paramètres.
// Le destructeur est défini pour libérer les ressources utilisées par l'objet (aucune ressource dans ce cas).
// La méthode afficherDetails() affiche les détails de la personne en utilisant les attributs nom, age et profession.
// Dans la fonction main(), un objet personne de type Personne est créé en utilisant le constructeur par défaut.
// La méthode afficherDetails() de l'objet personne est appelée pour afficher ses détails.
// À la fin de la fonction main(), l'appel automatique du destructeur se produit lorsque l'objet personne est détruit, libérant ainsi les ressources utilisées (aucune ressource à libérer dans ce cas).
// Ainsi, le programme démontre l'utilisation du constructeur par défaut, la méthode pour afficher les détails d'une personne et l'appel automatique du destructeur lorsqu'un objet est détruit.

#include <iostream>
#include <string>

// Création de la classe Personne avec les attributs privés string nom, int age, string profession
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

// Destructeur des données contenues dans la classe Personne
    ~Personne() {

    }

// fonction afficherDetails pour afficher les détails de l'objets appartenant à la classe personne
    void afficherDetails() {
        std::cout << "Les détails de la personne" << std::endl;
        std::cout << "Nom : " << nom << std::endl;
        std::cout << "Âge : " << age << std::endl;
        std::cout << "Profession : " << profession << std::endl;
    }
};

int main() {
    // Création de l'objet personne appartenant à la classe Personne et affichage des détails de l'objet
    Personne personne;
    personne.afficherDetails(); 

    return 0;
}