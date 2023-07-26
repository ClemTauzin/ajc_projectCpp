#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <vector>

#include "medicament.h"

class Patient{
protected:
    int m_Gravite;
    std::string m_Nom;
    std::vector<Medicament*> m_Medicaments;

public: 
    Patient(std::string nom, int gravite) :
        m_Nom(nom),m_Gravite(gravite){}

    void getGravite(){
        switch (m_Gravite)
        {
        case 1:
            std::cout << "Rouge";
            break;
        case 2:
            std::cout << "Orange";
            break;
        case 3:
            std::cout << "Vert";
            break;        
        default:
            std::cout <<"Gravitée non définie";
            break;
        }
    }
    void ajouterMedicaments(Medicament* medicament){
        m_Medicaments.push_back(medicament);
    }
    void afficherMedocs(){
        std::cout<<"Medicaments du patients :"<<std::endl;
        for (auto a : m_Medicaments)
        {
            a->afficher();
        }
        std::cout<<std::endl;
    }
    virtual void afficher() = 0;
};

#endif

