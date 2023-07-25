//192.168.1.5
#include <iostream>
#include <string>

// http 80 -8080 - http(secured)
const int PORT = 80;
const char* IP ="192.168.1.5";
// Connexion sur le serveur debian  
void connecterServeur(const std::string& adressIp, int numPort) {
               std::cout << " Tentative de connexion vers le serveur :" <<adressIp
                         << "sur le port : " << numPort << std::endl;
}                 

int main () {
    
                 bool ipLocal =(std::strcmp(IP, "192.168.1.5") == 0);

                       if(ipLocal) {
                                    std::cout << "Message : " << IP << " (serveur web )" << std::endl;
                       } else{

                                    std::cout << "Message : " << IP << " (serveur web )" << std::endl;
                       }

                    if (PORT == 80) {
                               std::cout << "Message : " << IP << " (serveur web )" << std::endl;
                    }
                    else{

                           std::cout << "Message : " << IP << " (serveur web )" << std::endl;
                    }

    connecterServeur(IP, PORT);
    return 0;                 
 }