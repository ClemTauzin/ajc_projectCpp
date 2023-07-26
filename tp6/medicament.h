#ifndef MEDICAMENT_H
#define MEDICAMENT_H

#include <iostream>
#include <string>

class Medicament{

    std::string m_Nom;
    int m_Dosage;

public :
    Medicament(std::string nom, int dosage);

    void afficher();
};


#endif
