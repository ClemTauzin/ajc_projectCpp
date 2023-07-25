#include <iostream>
#include <string>
#include <vector>

#define START std::cout<<"Starting Server"<<std::endl;
#define STOP std::cout<<"Good night"<<std::endl;

namespace ServeurApacheNamespace{
	class ServeurApache {
		public:
		void demarrer(){START};
		void arreter(){STOP};
	};
}

// Namespace anonyme pour les opérations SSH sur le serveur Debian 11
namespace {
    // Classe de base pour représenter un serveur SSH
    class ServeurSSH {
    protected:
        std::string ip; // Attribut pour stocker l'adresse IP du serveur SSH
        int port; // Attribut pour stocker le numéro de port du serveur SSH

    public:
        // Constructeur de la classe ServeurSSH
        ServeurSSH(const std::string& ip, int port) : ip(ip), port(port) {}

        // Fonction pour établir une connexion SSH au serveur
        void connecter() {
            std::cout << "Connexion SSH au serveur " << ip << " sur le port " << port << std::endl;
            // Code pour se connecter au serveur SSH réel
        }

        // Fonction virtuelle pour exécuter une commande sur le serveur
        virtual void executerCommande(const std::string& commande) {
            std::cout << "Exécution de la commande : " << commande << std::endl;
            // Code pour exécuter la commande sur le serveur SSH réel
        }

        // Fonction pour obtenir l'adresse IP du serveur
        std::string obtenirIP() const {
            return ip;
        }

        // Fonction pour obtenir le numéro de port du serveur
        int obtenirPort() const {
            return port;
        }
    };

    // Namespace anonyme pour les opérations spécifiques au serveur Debian 11
    namespace {
        // Classe dérivée spécifique pour le serveur Debian 11
        class ServeurDebian : public ServeurSSH {
        public:
            // Constructeur de la classe ServeurDebian
            ServeurDebian(const std::string& ip, int port) : ServeurSSH(ip, port) {}

            // Fonction pour mettre à jour les paquets sur le serveur Debian 11
            void mettreAJourPaquets() {
                std::cout << "Mise à jour des paquets sur le serveur Debian 11" << std::endl;
            
                // Code pour mettre à jour les paquets sur le serveur Debian 11 réel
            }

            // Fonction pour exécuter une commande spécifique à Debian 11 sur le serveur
            virtual void executerCommande(const std::string& commande) override {
                std::cout << "Exécution de la commande spécifique à Debian 11 : " << commande << std::endl;
                // Code pour exécuter la commande spécifique à Debian 11 sur le serveur SSH réel
            }
        };
    }
}

// Namespace nommé pour les opérations communes à tous les serveurs
namespace OperationsCommunes {
    // Fonction pour redémarrer le serveur
    void redemarrerServeur(ServeurSSH& serveur) {
        std::cout << "Redémarrage du serveur " << serveur.obtenirIP() << " sur le port " << serveur.obtenirPort() << std::endl;
        // Code pour redémarrer le serveur SSH réel
    }

	void redemarrerServeur(ServeurApacheNamespace::ServeurApache& serveur) {
	serveur.arreter();
	serveur.demarrer();
}

    // Fonction pour mettre à jour les paquets et redémarrer le service SSH sur le serveur Debian 11
    void mettreAJourEtRedemarrerSSH(ServeurDebian& serveurDebian) {
        serveurDebian.mettreAJourPaquets();
        serveurDebian.executerCommande("systemctl restart ssh");
    }
}

int main() {
	bool doitDemarrer = true;
	ServeurApacheNamespace::ServeurApache serveurApache;
	if (doitDemarrer){
		serveurApache.demarrer();
	}
	else {
		serveurApache.arreter();
	}
	OperationsCommunes::redemarrerServeur(serveurApache);
 

    // Utilisation du serveur Debian 11 via le namespace anonyme
    ServeurDebian serveurDebian("192.168.1.100", 22);
    serveurDebian.connecter();

    // Mise à jour des paquets et redémarrage du service SSH sur le serveur Debian 11
    OperationsCommunes::mettreAJourEtRedemarrerSSH(serveurDebian);

    // Utilisation d'un serveur générique via le namespace anonyme
    ServeurSSH serveurGenerique("192.168.1.200", 22);
    serveurGenerique.connecter();
    serveurGenerique.executerCommande("ls");

    // Utilisation des opérations communes via le namespace nommé
    OperationsCommunes::redemarrerServeur(serveurGenerique);

    return 0;
}
