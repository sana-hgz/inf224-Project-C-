#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Database.h"
#include "server.h"
const int PORT = 3331;

void startServer(Database& db) { 
    auto* server = new TCPServer([&](std::string const& request, std::string& response) {
        std::cout << " Requête reçue: " << request << std::endl;

        std::istringstream iss(request);
        std::string command, arg;
        iss >> command >> std::ws;
        std::getline(iss, arg);

        if (command == "displayMedia") {
            std::ostringstream os;
            db.displayMedia(arg, os);
            response = os.str();
        } else if (command == "playMedia") {
            db.playMedia(arg);
            response = "Lecture de " + arg;
        } else {
            response = "Commande inconnue: " + command;
        }

        std::cout << " Réponse envoyée : " << response << std::endl;
        return true;
    });

    std::cout << " Serveur en écoute sur le port " << PORT << "..." << std::endl;
    server->run(PORT);
}

