#ifndef PATIENTTYPE_H
#define PATIENTTYPE_H

#include <iostream>
#include <string>
#include <vector>

#include "patient.h"
#include "medicament.h"

class PatientUrgence : public Patient{
public:
    PatientUrgence(std::string nom, int gravite);

    void afficher() override;
};

class PatientNeuro : public Patient{
public:
    PatientNeuro(std::string nom, int gravite);

    void afficher() override;
};

class PatientGastro : public Patient{
public:
    PatientGastro(std::string nom, int gravite);

    void afficher() override;
};


#endif