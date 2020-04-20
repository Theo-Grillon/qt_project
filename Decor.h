//
// Created by Théo on 20/04/2020.
//

#ifndef QT_PROJECT_DECOR_H
#define QT_PROJECT_DECOR_H

#include "utilitaries.h"
#define tpsNuit 0
#define tpsJour 0
class Trou {
protected:
    int posX, assombrir;
public:
    Trou();
    void AfficheTrou();
};

class Etoile{
protected:
    int posX, posY, assombrir;
public:
    Etoile();
    void afficheEtoile();
    void depEtoile();
};

class Nuage {
protected:
    int posX, posY, depX;
public:
    Nuage();
    void afficheNuage();
    void depNuage();
};

class Arbre {
protected:
    int posX;
public:
    Arbre();
    void afficheArbre();
};

class Plateforme {
protected:
    int posX, posY, depX;
public:
    Plateforme();
    void affichePlateforme();
    void depPlateforme();
};

class Obstacle {
protected:
    int posX, posY, depY;
public:
    Obstacle();
    void afficheObstacle();
    void depObstacle();
};

#endif //QT_PROJECT_DECOR_H
