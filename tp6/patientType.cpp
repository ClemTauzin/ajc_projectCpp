#include <iostream>
#include <string>
#include <vector>

#include "patient.h"
#include "patientType.h"
#include "medicament.h"


PatientUrgence::PatientUrgence(std::string nom, int gravite) : Patient(nom, gravite){}

void PatientUrgence::afficher(){
    std::cout << "Nom du patient : " << m_Nom << std::endl;
    std::cout << "Gravité : ";
    getGravite();
    std::cout<<std::endl;
    afficherMedocs();

};

PatientNeuro::PatientNeuro(std::string nom, int gravite) : Patient(nom, gravite){}

void PatientNeuro::afficher(){
    std::cout << "Nom du patient : " << m_Nom << std::endl;
    std::cout << "Gravité : ";
    getGravite();
    std::cout<<std::endl;
    afficherMedocs();


};
PatientGastro::PatientGastro(std::string nom, int gravite) : Patient(nom, gravite){}

void PatientGastro::afficher(){
    std::cout << "Nom du patient : " << m_Nom << std::endl;
    std::cout << "Gravité : ";
    getGravite();
    std::cout<<std::endl;
    afficherMedocs();

};
