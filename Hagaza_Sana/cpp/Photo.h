#ifndef PHOTO_H
#define PHOTO_H

#include "BaseMultimedia.h"

class Photo : public BaseMultimedia {
private:
    double latitude;
    double longitude;

public:
    
    Photo() : BaseMultimedia("", ""), latitude(0.0), longitude(0.0) {}
    Photo(const std::string& name, const std::string& filePath, double latitude , double longitude )
        : BaseMultimedia(name, filePath), latitude(latitude), longitude(longitude) {}
    std::string getClassName() const override { return "Photo"; }
    //serialisation
    void serialize(std::ostream& os) const override {
        BaseMultimedia::serialize(os);
        os << latitude << "\n" << longitude << "\n";
    }
    //deserialisation
    void deserialize(std::istream& is) override {
        BaseMultimedia::deserialize(is);
        is >> latitude >> longitude;
        is.ignore(); // Pour éviter les problèmes de retour à la ligne
    }
    // Getters
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }

    // Setters
    void setLatitude(double lat) { latitude = lat; }
    void setLongitude(double lon) { longitude = lon; }

    // Méthode d'affichage
    void display(std::ostream& os) const override {
        os << "Photo: " << getName() << "\n"
           << "File Path: " << getFilePath() << "\n"
           << "Latitude: " << latitude << ", Longitude: " << longitude << std::endl;
    }

    // Méthode pour afficher la photo
    void play() const override {
        std::string command = "imagej " + getFilePath() + " &";
        system(command.c_str());  // Lance l'image avec imagej
    }
};

#endif // PHOTO_H
