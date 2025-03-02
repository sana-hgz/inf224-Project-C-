//
// main.cpp
// Created on 21/10/2018
//
#include <iostream>
#include <vector>
#include "BaseMultimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "Database.h"

#define MODE_SERVER  // Active la version serveur

#include "server.h"

int main() {

    
    Database db;

    //  Création des objets multimédia
    auto p1 = db.createPhoto("tparis", "./tparis.jpg", 40, 20);
    auto v1 = db.createVideo("palaiseau", "./video.mp4", 5);
    //int chapters[] = {100, 200, 300};
    //auto f1 = db.createFilm("Inception", "/path/to/inception.mp4", 500, chapters, 3);

    //  Création des groupes
    auto vacances = db.createGroup("Vacances");
    //auto films = db.createGroup("Films");

    //  Ajout aux groupes
    vacances->push_back(p1);
    vacances->push_back(v1);
    //films->push_back(f1);
    //films->push_back(v1);
    #ifdef MODE_SERVER
    std::cout << "Démarrage du serveur..." << std::endl;
    startServer(db);  // Appelle la fonction du serveur
    #else

    //  Affichage
    db.displayMedia("Tour Eiffel", std::cout);
    db.displayGroup("Vacances", std::cout);

    //  Suppression d'un média et vérification automatique
    std::cout << "\nSuppression de \"Tour Eiffel\"...\n";
    db.deleteMedia("Tour Eiffel");

    #endif

    return 0;
}