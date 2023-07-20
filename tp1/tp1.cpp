#include <iostream>
#include <string>
#include <vector>

class Service {
    protected:
        std::string nomService;
        double prixService;

    public:
    Service (const std::string& _nomService, int _prixService) : nomService(_nomService), prixService(_prixService) {};

    virtual void afficherDetails(){
        std::cout<<"Nom du service : "<< nomService << " ----> Prix (en €): " << prixService << std::endl;
    }
};


class ServiceDeBase : public Service {
    public:
        ServiceDeBase (const std::string& _nomService, int _prixService) : Service(_nomService, _prixService){};
        void afficherDetails() override{
        std::cout<<"Service de Base\n"<<"Nom du service : "<< nomService << " ----> Prix (en €): " << prixService << std::endl;
        }
};

class ServicePremium : public Service {
    private:
    int abmt;
    public:
        ServicePremium (const std::string& _nomService, int _prixService) : Service(_nomService, _prixService){};
        void afficherDetails() override{
        std::cout<<"Service Premium\n"<<"Nom du service : "<< nomService << " ----> Prix (en €): " << prixService << " (durée d'abonnement : "<<abmt<<" mois)"<< std::endl;
        }
};

class CentreAffaires {
    private:
        std::vector<Service*> newService;
    public:
        void ajoutService(Service* service){
            newService.push_back(service);
    }
        void afficherServices(){
            for(int i = 0; i < newService.size(); i++){
                newService[i]->afficherDetails();
            }
        }
};

int main() {
    ServiceDeBase service1("Bureau Partagé", 50.0);
    ServicePremium service2("Salle de Réunion", 100.0);
    ServiceDeBase service3("Accès internet", 20.0);
    CentreAffaires NewCenter;
    NewCenter.ajoutService(&service1);
    NewCenter.ajoutService(&service2);
    NewCenter.ajoutService(&service3);
    NewCenter.afficherServices();
    
    return 0;
}