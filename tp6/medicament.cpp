#include "medicament.h"

Medicament::Medicament(std::string nom, int dosage)
    :m_Nom(nom),m_Dosage(dosage){}

void Medicament::afficher()
{
    std::cout << "Nom : " << m_Nom << " / Dosage : " << m_Dosage << std::endl;
}
