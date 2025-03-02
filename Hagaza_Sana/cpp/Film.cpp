#include "Film.h"
#include <iostream>
#include <cstring> 

// Constructeur avec copie des chapitres
Film::Film(const std::string& name, const std::string& path, int duration, const int* chapters, int count)
    : Video(name, path, duration), chapterCount(count) {
    setChapters(chapters, count);
}

// Constructeur de copie
Film::Film(const Film& other) : Video(other), chapterCount(other.chapterCount) {
    setChapters(other.chapters, other.chapterCount);
}

// Opérateur d'affectation
Film& Film::operator=(const Film& other) {
    if (this != &other) { // Vérifie l'auto-affectation
        Video::operator=(other); // Copie des attributs de Video
        setChapters(other.chapters, other.chapterCount);
    }
    return *this;
}

// Destructeur
Film::~Film() {
    delete[] chapters; // Libération de la mémoire
}

// Modifieur pour stocker un nouveau tableau de chapitres
void Film::setChapters(const int* newChapters, int count) {
    // Supprime l'ancien tableau pour éviter les fuites mémoire
    delete[] chapters;  

    if (count > 0) {
        // Alloue un nouveau tableau de la bonne taille
        chapters = new int[count];

        // Copie manuellement les valeurs avec une boucle
        for (int i = 0; i < count; i++) {
            chapters[i] = newChapters[i];  // Copie chaque élément un par un
        }
    } else {
        chapters = nullptr;  // Aucun chapitre, on évite une allocation inutile
    }

    chapterCount = count;  // Met à jour le nombre de chapitres
}


// Affichage des infos du film et des chapitres
void Film::display(std::ostream& os) const {
    Video::display(os);
    os << "Chapters (" << chapterCount << "): ";
    for (int i = 0; i < chapterCount; i++) {
        os << chapters[i] << "s ";
    }
    os << std::endl;
}