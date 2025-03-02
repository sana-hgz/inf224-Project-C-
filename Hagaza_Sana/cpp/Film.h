#ifndef FILM_H
#define FILM_H

#include "Video.h"
#include "BaseMultimedia.h"

class Film : public Video {
private:
    int* chapters = nullptr; // Tableau dynamique de chapitres
    int chapterCount = 0; // Nombre de chapitres

public:
    // Constructeurs
    Film(const std::string& name, const std::string& path, int duration, const int* chapters, int count);
    Film(const Film& other); // Constructeur de copie
    Film& operator=(const Film& other); // Opérateur d'affectation
    ~Film(); // Destructeur

    // Modifieur pour les chapitres
    void setChapters(const int* chapters, int count);

    // Accesseurs
    const int* getChapters() const { return chapters; }
    int getChapterCount() const { return chapterCount; }

    // Affichage
    void display(std::ostream& os) const override;
};

#endif // FILM_H
