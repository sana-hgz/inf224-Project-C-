#ifndef GROUP_H
#define GROUP_H
#include <memory>

#include <list>
#include <string>
#include <iostream>
#include "BaseMultimedia.h"
//  Définition d'un alias pour les smart pointers
using BaseMultimediaPtr = std::shared_ptr<BaseMultimedia>;

class Group : public std::list<BaseMultimediaPtr> {
private:
    std::string name;  // Nom du groupe

public:
    // Constructeur
    Group(const std::string& groupName) : name(groupName) {}

    // Accesseur du nom du groupe
    std::string getName() const { return name; }

    // Affichage du groupe et de ses éléments
    void display(std::ostream& os) const {
        os << "Groupe: " << name << std::endl;
        for (const auto& item : *this) {
            item->display(os);  // Appel polymorphique à `display()`
        }
    }
};

#endif // GROUP_H