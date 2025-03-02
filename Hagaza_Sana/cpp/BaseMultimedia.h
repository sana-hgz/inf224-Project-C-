#ifndef BASEMULTIMEDIA_H
#define BASEMULTIMEDIA_H

#include <string>
#include <iostream>
#include <fstream>
#include <string>

class BaseMultimedia {
private:
    std::string name;          // Nom de l'objet multimédia                                                                                                                                                        
    std::string filePath;      // Chemin complet du fichier associé                                                                                                                                                

public:
    // Constructeurs                                                                                                                                                                                               
    //BaseMultimedia() = default; // Constructeur sans argument                                                                                                                                                    
    BaseMultimedia(const std::string& name, const std::string& filePath);
    // Destructeur                                                                                                                                                                                                 
    virtual ~BaseMultimedia() {                                                                                                                                                 
        std::cout << "Destruction de " << name << std::endl;
    }
    virtual std::string getClassName() const = 0; // Retourne le nom de la classe

    virtual void serialize(std::ostream& os) const {
        os << getClassName() << "\n" << name << "\n" << filePath << "\n";
    }

    virtual void deserialize(std::istream& is) {
        std::getline(is, name);
        std::getline(is, filePath);
    }

    friend std::ostream& operator<<(std::ostream& os, const BaseMultimedia& obj) {
        obj.serialize(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, BaseMultimedia& obj) {
        obj.deserialize(is);
        return is;
    }
    // Getters                                                                                                                                                                                                     
    std::string getName() const;
    std::string getFilePath() const;

    // Setters                                                                                                                                                                                                     
    void setName(const std::string& name);
    void setFilePath(const std::string& filePath);

    // Méthode d'affichage                                                                                                                                                                                         
    virtual void display(std::ostream& os) const;
    virtual void play() const = 0; // Méthode pure virtuelle                                                                                                                                                       

};

#endif // BASEMULTIMEDIA_H   