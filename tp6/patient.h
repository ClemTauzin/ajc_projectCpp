#ifndef PATIENT_H
#define PATIENT_H
#define R "Rouge"
#define O "Orange"
#define V "Vert"

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
            std::cout << R;
            break;
        case 2:
            std::cout << O;
            break;
        case 3:
            std::cout << V;
            break;        
        default:
            std::cout <<"Gravitée non définie";
            break;
        }
        std::cout << std::endl;
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
    }
    virtual void afficher() = 0;

    ~Patient(){}
};

#endif

