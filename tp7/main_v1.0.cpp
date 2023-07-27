/**
 * @brief cpp practice exercice - ssh connection
 * @authors Clement Tauzin Olivier Wafflard
 * @date 2023/07/27
 *
 * @version 1.0 First theoretical version with first logging command
 *
 * The aim of this exercice is to practice about several notions in C++
 * such as
 * - class creation
 * - polymorphism
 * - vector utilisation
 * - trying to connect a server in ssh connection
 *
 * To Compile : in the same folder as every file as known :
 *  - main.cpp
 *
 * To compile, enter the following command : g++ -std=c++11 *.cpp
 * To execute, enter the following command : ./a.out
 *
 * test on Mac OSX : Mojave 10.14.6 and Debian 11
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <typeinfo>


/**
 * @brief SSHConnection Constructor - abstratc virtual base for SSH Connection
 */
class SSHConnection {

protected:
    std::string m_UserName;
    std::string m_IP;
    int m_Port;

public:

    SSHConnection(const std::string UserName, std::string IP, int Port)
        : m_UserName(UserName), m_IP(IP), m_Port(Port){}

    virtual void connect() = 0;
    virtual void sendCommand(const std::string& command) = 0;
    virtual void disconnect() = 0;


    std::string getUserName() const {return m_UserName;}
    std::string getIp() const {return m_IP;}
    int getPort() const {return m_Port;}

};


/**
 * @brief The UserSSHConnection class
 */
class UserSSHConnection : public SSHConnection {
private:
    std::string password;

public:
    UserSSHConnection(const std::string& _username, std::string _IP, int _port, const std::string& _password)
        : SSHConnection(_username, _IP, _port), password(_password){}

    void connect() override {
        std::cout<<"Connexion en USER au serveur"<<std::endl;
        // Ajoutez ici le code pour établir la connexion SSH en tant qu'utilisateur.
    }

    void sendCommand(const std::string& command) override {
        // Ajoutez ici le code pour envoyer une commande sur la connexion SSH en tant qu'utilisateur.
    }

    void disconnect() override {
        // Ajoutez ici le code pour fermer la connexion SSH en tant qu'utilisateur.
    }
};


/**
 * @brief The AdminSSHConnection class
 */
class AdminSSHConnection : public SSHConnection {
private:
    std::string adminKey;

public:

    AdminSSHConnection(const std::string& _username, std::string _IP, int _port, const std::string& _adminKey)
        : SSHConnection(_username, _IP, _port), adminKey(_adminKey){}

    void connect() override {
        std::cout<<"Connexion en ADMIN au serveur"<<std::endl;
        // Ajoutez ici le code pour établir la connexion SSH en tant qu'utilisateur.
    }

    void sendCommand(const std::string& command) override {
        // Ajoutez ici le code pour envoyer une commande sur la connexion SSH en tant qu'utilisateur.
    }

    void disconnect() override {
        // Ajoutez ici le code pour fermer la connexion SSH en tant qu'utilisateur.
    }
};

/**
 * @brief The GuestSSHConnection class
 */
class GuestSSHConnection : public SSHConnection{
public:
    GuestSSHConnection(const std::string UserName, std::string IP, int Port) :
        SSHConnection(UserName, IP, Port){}

    void connect() override {
        std::cout<<"Connexion en GUEST au serveur"<<std::endl;

        // Ajoutez ici le code pour établir la connexion SSH en tant qu'invité.
    }

    void sendCommand(const std::string& command) override {
        // Ajoutez ici le code pour envoyer une commande sur la connexion SSH en tant qu'invité.
    }

    void disconnect() override {
        // Ajoutez ici le code pour fermer la connexion SSH en tant qu'invité.
    }
};


/**
 * @brief The SSHServer class
 */
class SSHServer {

private:
    std::vector<SSHConnection*> connections;
    // Méthode privée pour vérifier si OpenSSH Server est installé

    bool isOpenSSHInstalled(){
        // Ajoutez ici le code pour vérifier si OpenSSH Server est installé.
        // Vous pouvez utiliser la méthode privée installOpenSSHServer()
        // pour installer OpenSSH Server automatiquement si nécessaire.
        return true;
    }

    // Méthode privée pour installer OpenSSH Server
    void instal(){
        std::cout<<"c'est installé youpi"<<std::endl;
        // Ajoutez ici le code pour installer OpenSSH Server.
    }

public:

    // Méthode publique pour ajouter une connexion au serveur
    void addConnection(SSHConnection* connection){
        connections.push_back(connection);
        std::cout<<"Ajout au serveur realisée."<<std::endl;
    }

    // Méthode publique pour exécuter des commandes sur les connexions
    void executeConnections() {
        if (!isOpenSSHInstalled()) {
            std::cout<<"Open SSH n'est pas installé sur la machine du client"<<std::endl;
        }
        for (SSHConnection* connection : connections) {
            connection->connect();
        }
    }

    void executeCommands() {
        for (SSHConnection* connection : connections) {

            std::string logstr("echo \"");
            logstr.append(connection->getUserName().c_str());
            logstr.append(" ; ");

            logstr.append(connection->getIp().c_str());
            logstr.append(" ; \" $(date) >> log.txt");

            system(logstr.c_str());
        }
    }
    // Méthode publique pour nettoyer les connexions
    void cleanConnections() {
        for (SSHConnection* connection : connections) {
            delete connection;
        }
        connections.clear();
    }

    ~SSHServer(){}
};


/**
 ****************************************************************************
 * @brief main                                                          MAIN
 * @return
 * **************************************************************************
 */
int main() {
    SSHServer server;

    GuestSSHConnection guest1("John Doe", "192.168.1.6", 22);
    GuestSSHConnection guest2("Malika", "192.168.1.7", 22);

    UserSSHConnection  user("user","192.168.1.1",22,"root");
    AdminSSHConnection admin("admin","192.168.1.2",22,"rsabidulechouette");

    server.addConnection(&guest1);
    server.addConnection(&guest2);
    server.addConnection(&user);
    server.addConnection(&admin);

    server.executeConnections();
    server.executeCommands();


    return 0;
}
