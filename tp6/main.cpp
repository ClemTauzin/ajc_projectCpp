#include <iostream>
#include <string>
#include <vector>

#include "patient.h"
#include "patientType.h"
#include "medicament.h"


class CabinetMedical{

    private :
    
    std::vector<Patient*> patients;

    public :

    void ajouterPatient(Patient* patient){
        patients.push_back(patient);
    }

    void afficherPatients(){

        std::cout << "Type de patients souhaité (1:urgence) "
                  << " (2:neuro) (3:gastro) (0:tous) " << std::endl;

        int choix = 0;

        std::cin >> choix;

        for(auto p : patients){

            PatientUrgence* pu = dynamic_cast<PatientUrgence*>(p);
            PatientNeuro*   pn = dynamic_cast<PatientNeuro*>(p);
            PatientGastro*  pg = dynamic_cast<PatientGastro*>(p);

            switch(choix){
            case 1 :
                if(pu != nullptr){
                    pu->afficher();
                    std::cout << " and id : " << typeid(pu).name() << std::endl;
                }
                break;
            case 2 :
                if(pn != nullptr){
                    pn->afficher();
                    std::cout << " and id : " << typeid(pn).name() << std::endl;
                }
                break;
            case 3 :
                if(pg != nullptr){
                    pg->afficher();
                    std::cout << " and id : " << typeid(pg).name() << std::endl;
                }
                break;
            case 0 :
                    p->afficher();
                    std::cout << " and id : " << typeid(p).name() << std::endl;
                break;
            default :
                    std::cout << "commande invalide" << std::endl;
            }
        }
    }
    ~CabinetMedical(){}
};



int main(){
    PatientUrgence patient1("Jonh Doe", 2);
    PatientNeuro patient2("Rain Man", 3);
    PatientGastro patient3("Elisabeth", 1);
    PatientGastro patient4("Elisabeth2", 3);

    Medicament medoc1("Aspirine", 4);
    Medicament medoc2("Smecta", 8);
    
    patient1.ajouterMedicaments(&medoc1);
    patient3.ajouterMedicaments(&medoc2);
    
    CabinetMedical cabinet;
    cabinet.ajouterPatient(&patient1);
    cabinet.ajouterPatient(&patient2);
    cabinet.ajouterPatient(&patient3);
    cabinet.ajouterPatient(&patient4);

    cabinet.afficherPatients();

    std::cout << std::endl;

    return 0;

}



