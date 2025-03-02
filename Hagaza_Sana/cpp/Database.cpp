#include "Database.h"
#include <iostream>


//  Création d'une Photo et ajout à la table
BaseMultimediaPtr Database::createPhoto(const std::string& name, const std::string& path, double lat, double lon) {
    auto photo = std::make_shared<Photo>(name, path, lat, lon);
    mediaTable[name] = photo;
    return photo;
}

//  Création d'une Vidéo et ajout à la table
BaseMultimediaPtr Database::createVideo(const std::string& name, const std::string& path, int duration) {
    auto video = std::make_shared<Video>(name, path, duration);
    mediaTable[name] = video;
    return video;
}

//  Création d'un Film et ajout à la table
BaseMultimediaPtr Database::createFilm(const std::string& name, const std::string& path, int duration, const int* chapters, int count) {
    auto film = std::make_shared<Film>(name, path, duration, chapters, count);
    mediaTable[name] = film;
    return film;
}

//  Création d'un groupe et ajout à la table
GroupePtr Database::createGroup(const std::string& name) {
    auto group = std::make_shared<Group>(name);
    groupTable[name] = group;
    return group;
}

//  Affichage d'un objet multimédia
void Database::displayMedia(const std::string& name, std::ostream& os) const {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        it->second->display(os);
    } else {
        os << "Objet multimédia \"" << name << "\" introuvable." << std::endl;
    }
}

//  Affichage d'un groupe
void Database::displayGroup(const std::string& name, std::ostream& os) const {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        it->second->display(os);
    } else {
        os << "Groupe \"" << name << "\" introuvable." << std::endl;
    }
}

//  Jouer un objet multimédia
void Database::playMedia(const std::string& name) const {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        it->second->play();  
    } else {
        std::cerr << "Impossible de jouer \"" << name << "\", média introuvable." << std::endl;
    }
}

//  Suppression d'un objet multimédia
void Database::deleteMedia(const std::string& name) {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        for (auto& groupPair : groupTable) {  
            auto& group = groupPair.second;  // Récupère le pointeur du groupe
            group->remove(it->second);       // Supprimer l'objet multimédia du groupe
        }
        mediaTable.erase(it);  // Supprime de la table
        std::cout << "Objet multimédia \"" << name << "\" supprimé." << std::endl;
    } else {
        std::cerr << "Objet multimédia \"" << name << "\" introuvable." << std::endl;
    }
}


//  Suppression d'un groupe
void Database::deleteGroup(const std::string& name) {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        groupTable.erase(it);  // Suppression de la table
        std::cout << "Groupe \"" << name << "\" supprimé." << std::endl;
    } else {
        std::cerr << "Groupe \"" << name << "\" introuvable." << std::endl;
    }
}
