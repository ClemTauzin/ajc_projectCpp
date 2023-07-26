#include <iostream>
#include <string>
#include <vector>

#include "patient.h"
#include "patientType.h"
#include "medicament.h"

int main(){
    PatientUrgence patient1("Jonh Doe", 2);
    PatientNeuro patient2("Rain Man", 3);
    PatientGastro patient3("Elisabeth", 1);

    Medicament medoc1("Aspirine", 4);
    Medicament medoc2("Smecta", 8);
    
    patient1.ajouterMedicaments(&medoc1);
    patient3.ajouterMedicaments(&medoc2);
    
    patient1.afficher();
    patient2.afficher();
    patient3.afficher();




        return 0;

}



