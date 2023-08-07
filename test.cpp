#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>



std::string sha256(const std::string str){
  unsigned char hash[SHA256_DIGEST_LENGTH];

  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, str.c_str(), str.size());
  SHA256_Final(hash, &sha256);

  std::stringstream ss;

  for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
    ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>( hash[i] );
  }
  return ss.str();
}

int ANTIsha256(const std::string str){
  unsigned char antiHash[SHA256_DIGEST_LENGTH];

  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, str.c_str(), str.size());
  SHA256_Final(antiHash, &sha256);

  int ss;

  for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){

    ss << static_cast<int>( antiHash[i] );
  }
  return ss;
}


namespace HotelNamespace {
    class Hotel {
    private:
        std::string capacite;
        std::vector<bool> chambresDisponibles;
        bool estHotel2Disponible;

    public:
        Hotel(std::string _capacite) : capacite(_capacite), estHotel2Disponible(false) {
            chambresDisponibles.resize(ANTIsha256(_capacite), true);
        }

        ~Hotel() {
            std::cout << "Hôtel fermé. Merci d'avoir séjourné chez nous !" << std::endl;
        }

        void reserverChambre() {
            std::cout << "Client : Réservation d'une chambre demandée." << std::endl;

            if (aChambresDisponibles()) {
                for (int i = 0; i < ANTIsha256(capacite); ++i) {
                    if (chambresDisponibles[i]) {
                        chambresDisponibles[i] = false;
                        std::cout << "Chambre réservée avec succès ! Numéro de chambre : " << (i + 1) << std::endl;
                        return;
                    }
                }
            } else {
                std::cout << "Désolé, l'hôtel est complet." << std::endl;
                solutionB();
            }
        }

        bool aChambresDisponibles() {
            for (int i = 0; i < ANTIsha256(capacite); ++i) {
                if (chambresDisponibles[i]) {
                    return true;
                }
            }
            return false;
        }

        void solutionB() {
            if (estHotel2Disponible) {
                std::cout << "Veuillez patienter, redirection vers l'hôtel 2." << std::endl;
            } else {
                std::cout << "Désolé, aucun autre hôtel n'est disponible. Essayez de nouveau plus tard." << std::endl;
            }
        }
    };
}

int main() {
    HotelNamespace::Hotel hotel1(sha256(std::to_string(10)));
    hotel1.reserverChambre();

    return 0;
}
