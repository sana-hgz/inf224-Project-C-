#include "BaseMultimedia.h"

// Constructeur avec arguments                                                                                                                                                                                     
BaseMultimedia::BaseMultimedia(const std::string& name, const std::string& filePath)
    : name(name), filePath(filePath) {}

// Getters                                                                                                                                                                                                         
std::string BaseMultimedia::getName() const {
    return name;
}

std::string BaseMultimedia::getFilePath() const {
    return filePath;
}

// Setters                                                                                                                                                                                                         
void BaseMultimedia::setName(const std::string& name) {
    this->name = name;
}

void BaseMultimedia::setFilePath(const std::string& filePath) {
    this->filePath = filePath;
}

// Méthode d'affichage                                                                                                                                                                                             
void BaseMultimedia::display(std::ostream& os) const {
    os << "Name: " << name << "\nFile Path: " << filePath << std::endl;
}


