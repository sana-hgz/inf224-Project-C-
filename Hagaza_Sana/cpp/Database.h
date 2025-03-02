#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <memory>  
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "MultiMedia.h"

using BaseMultimediaPtr = std::shared_ptr<BaseMultimedia>;
using GroupePtr = std::shared_ptr<Group>;

class Database {
private:
    std::map<std::string, BaseMultimediaPtr> mediaTable;  // Table des objets multimédias
    std::map<std::string, GroupePtr> groupTable;  // Table des groupes

public:
    Database() = default;

    // Création d'objets multimédia et ajout à la table
    BaseMultimediaPtr createPhoto(const std::string& name, const std::string& path, double lat, double lon);
    BaseMultimediaPtr createVideo(const std::string& name, const std::string& path, int duration);
    BaseMultimediaPtr createFilm(const std::string& name, const std::string& path, int duration, const int* chapters, int count);

    // Création d'un groupe et ajout à la table
    GroupePtr createGroup(const std::string& name);

    // Recherche et affichage
    void displayMedia(const std::string& name, std::ostream& os) const;
    void displayGroup(const std::string& name, std::ostream& os) const;

    // Jouer un média
    void playMedia(const std::string& name) const;

    // Suppression d'un média ou d'un groupe
    void deleteMedia(const std::string& name);
    void deleteGroup(const std::string& name);
    //serialisation 
    /*void addMedia(const std::shared_ptr<BaseMultimedia>& media) {
        mediaTable[media->getClassName() + "_" + media->getName()] = media;
    }
    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Erreur d'ouverture du fichier !" << std::endl;
            return;
        }

        for (const auto& [key, media] : mediaTable) {
            file << *media << "\n";  // Utilise operator<< pour sérialiser
        }
        file.close();
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Erreur d'ouverture du fichier !" << std::endl;
            return;
        }

        std::string className;
        while (std::getline(file, className)) {
            std::shared_ptr<BaseMultimedia> media;

            if (className == "Photo") {
                media = std::make_shared<Photo>();
            } else if (className == "Video") {
                media = std::make_shared<Video>();
            } else {
                std::cerr << "Classe inconnue : " << className << std::endl;
                continue;
            }

            file >> *media;
            addMedia(media);
        }
        file.close();
    }*/
 };
#endif // DATABASE_H
