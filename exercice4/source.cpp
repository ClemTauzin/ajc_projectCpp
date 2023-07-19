#include <iostream>
#include <string>


class Personne{
    protected:
        std::string name;
        int age;
        std::string job;
    public:
        void afficherDetails(){
            std::cout<<"Les détails de la personne"<<std::endl;
        };
        int modifierAge(int age);
        std::string modifierNom(std::string name);

        explicit Personne(const std::string& _name, int _age, std::string _job) : name(_name), age(_age), job(_job){};

        void afficher(){
            std::cout<<"nom : "<< name << ", age : "<< age<< ", profession : "<< job << std::endl;
        }
    ~Personne(){
        std::cout<<"Données détruites"<<std::endl;

    };
};

class Etudiant : public Personne {
    public:
        void afficherDetails() {
            std::cout<<"Les détails de l'étudiant"<<std::endl;
        };
        std::string modifierNom(std::string name);

    explicit Etudiant(const std::string& _name, int _age, std::string _job) : Personne(_name, _age, _job){};
};


int main(){
    Personne personne("Jonh Doe", 17, "boulanger");
    Personne personne2(personne);
    int age_personne3 = 25;
    Personne personne3("Joséphine", age_personne3, "ange gardien");

    Etudiant etudiant1("Toto", 5, "architecte");

    personne.afficher();
    personne.afficherDetails();

    personne2.afficher();
    personne3.afficher();
    etudiant1.afficher();

    return 0;
}