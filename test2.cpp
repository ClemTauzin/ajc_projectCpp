/*
    Changer la classe et la gravité d'un patient par son nom
    Le changement s'effectue en créant un nouveau pointeur ajouté au vecteur du cabinet.
    L'ancien pointeur est libéré et supprimé du vecteur
    return: int reponse
    Si la classe et la gravité du patient sont différentes, retourne 1 (operation effectuée)
    Si la classe et la gravité du patient sont incorrectes, retourne 0 (operation non effectuée)
    Si la classe et la gravité du patient sont identiques, retourne 0   (operation non effectuée)
    Si le patient n'est pas trouvé, retourne -1 (operation non effectuée)
*/
int Cabinet::CabinetMedical::changerGravite(std::string nom, int gravite, int infoComplementaire)
{
    int reponse = 1;
    PatientNamespace::PatientGeneral *gravPatient = rechercherPatientParNom(nom);

    if (gravPatient == nullptr)
    {
        return -1;
    }
    else
    {
        gravPatient->afficher();

        bool choixVert = gravite == NUM_GRAVITE_VERT;
        bool choixOrange = gravite == NUM_GRAVITE_ORANGE;
        bool choixRouge = gravite == NUM_GRAVITE_ROUGE;
        PatientNamespace::PatientGeneral *updPatient = nullptr;
        // Modification seulement si la gravité choisi est différente de l'initiale
        if (choixVert && dynamic_cast<PatientNamespace::PatientVert *>(gravPatient) == nullptr)
        {
            updPatient = new PatientNamespace::PatientVert(gravPatient, infoComplementaire);
        }
        else if (choixOrange && dynamic_cast<PatientNamespace::PatientOrange *>(gravPatient) == nullptr)
        {
            updPatient = new PatientNamespace::PatientOrange(gravPatient, infoComplementaire);
        }
        else if (choixRouge && dynamic_cast<PatientNamespace::PatientRouge *>(gravPatient) == nullptr)
        {
            updPatient = new PatientNamespace::PatientRouge(gravPatient, infoComplementaire);
        }
        else
        {
            reponse = 0;
        }

        if (updPatient != nullptr)
        {
            supprimerPatient(gravPatient->getNom());
            ajouterPatient(updPatient);
        }
        gravPatient = nullptr;
    }

    return reponse;
}