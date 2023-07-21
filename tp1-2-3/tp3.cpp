// Clément Tauzin
#include <iostream>
#include <string>
#include <vector>

namespace Services {
    class Service {
        protected:
            std::string nomService;
            double prixService;

        public:
        Service (const std::string& _nomService, int _prixService) : nomService(_nomService), prixService(_prixService) {};

        virtual void afficherDetails() {
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
            ServicePremium (const std::string& _nomService, int _prixService, int _abmt) : Service(_nomService, _prixService), abmt(_abmt){};
            void afficherDetails() override{
            std::cout<<"Service Premium\n"<<"Nom du service : "<< nomService << " ----> Prix (en €): " << prixService << " (durée d'abonnement : "<<abmt<<" mois)"<< std::endl;
            }
    };
}
namespace CentreAffaires{
    class CentreAffaires {
        private:
            std::vector<Services::Service*> newService;
        public:
            void ajoutService(Services::Service* service){
                newService.push_back(service);
            }
            void afficherServices(){
                for(int i = 0; i < newService.size(); i++){
                    newService[i]->afficherDetails();
                }
            }
        ~CentreAffaires(){
        std::cout<<"mémoire CentreAffaires effacée"<<std::endl;
        };
    };
}
namespace ServicesJuridiques{
    class ServiceJuridique{
        protected:
            std::string nomService;
            double honoraires;
        public:
            ServiceJuridique(const std::string& _nomService, double _honoraires) : nomService(_nomService), honoraires(_honoraires){};
            virtual void afficherDetails(){
            std::cout<<"Nom du service : "<< nomService << " ----> Prix (en €): " << honoraires << std::endl;
        }
    };
    class ConsultationJuridique : public ServiceJuridique{
        private:
            int dureeConsultation;
        public:
            ConsultationJuridique(const std::string& _nomService, double _honoraires, int _duree) : ServiceJuridique(_nomService, _honoraires), dureeConsultation(_duree) {};
            void afficherDetails() override{
            std::cout<<"Nom du service : "<< nomService << " ----> Prix (en €): " << honoraires << " (durée de la consultation : "<< dureeConsultation << " minutes)"<< std::endl;
            }
    };

    class ServiceContentieux : public ServiceJuridique{
        private:
            std::string typeContentieux;
        public:
            ServiceContentieux(const std::string& _nomService, double _honoraires, std::string _type) : ServiceJuridique(_nomService, _honoraires), typeContentieux(_type) {};
            void afficherDetails() override{
            std::cout<<"Nom du service : "<< nomService << " ----> Prix (en €): " << honoraires << "(type de contentieux : "<< typeContentieux << " minutes)"<< std::endl;
        };
    };
};
namespace CabinetAvocats{
    class Avocats {
        private:
            std::string nomAvocat;
            std::string specialite;
        public:
            Avocats(const std::string& _nomAvocat, std::string _spe) : nomAvocat(_nomAvocat), specialite(_spe) {};
            virtual void afficherDetails(){
            std::cout<<"Nom de l'avocat : "<< nomAvocat << " ----> specialité: " << specialite << std::endl;
            }
    };
    class Cabinet{
        private:
            std::vector<ServicesJuridiques::ServiceJuridique*> Cabinet;
            std::vector<Avocats*> Avocat;
        public:
            void addServiceJuridique(ServicesJuridiques::ServiceJuridique* service){
                Cabinet.push_back(service);
            }
            void addAvocat(Avocats* avocat){
                Avocat.push_back(avocat);
            }
            void afficherServicesJuridiques(){
                for (int i = 0; i < Cabinet.size(); i++)
                {
                    Cabinet[i]->afficherDetails();
                }
            }
            void afficherAvocats(){
                for (int i = 0; i < Avocat.size(); i++)
                {
                    Avocat[i]->afficherDetails();
                }               
            }
        ~Cabinet(){
            std::cout<<"Mémoire Cabinet effacée"<<std::endl;
        };
    };
};



int main() {
    Services::ServiceDeBase service1("Bureau Partagé", 50.0);
    Services::ServicePremium service2("Salle de Réunion", 100.0, 12);
    Services::ServiceDeBase service3("Accès internet", 20.0);

    CentreAffaires::CentreAffaires NewCenter;
    NewCenter.ajoutService(&service1);
    NewCenter.ajoutService(&service2);
    NewCenter.ajoutService(&service3);
    NewCenter.afficherServices();
    

    CabinetAvocats::Cabinet NewCabinet;
    ServicesJuridiques::ServiceContentieux serviceC1("Service Voisinage", 500, "affaires civiles");
    ServicesJuridiques::ConsultationJuridique serviceC2("Service d'accueil", 150, 30);
    CabinetAvocats::Avocats lawyer1("Maitre Arnak", "Droit des affaires");
    CabinetAvocats::Avocats lawyer2("Maitre LaPaye", "Droits Financiers");
    NewCabinet.addAvocat(&lawyer1);
    NewCabinet.addAvocat(&lawyer2);
    NewCabinet.addServiceJuridique(&serviceC1);
    NewCabinet.addServiceJuridique(&serviceC2);
    NewCabinet.afficherServicesJuridiques();
    NewCabinet.afficherAvocats();

    return 0;
}