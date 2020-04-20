//
// Created by Théo on 20/04/2020.
//

#ifndef QT_PROJECT_DECOR_H
#define QT_PROJECT_DECOR_H

#include "utilitaries.h"
#define tpsNuit 0
#define tpsJour 0


class Obstacle {
protected:
    int posX, posY, depX;
public:
    Obstacle();
    virtual void afficheObstacle();
    virtual void depObstacle();
};

class Trou : public Obstacle {
public:
    Trou();
    virtual void afficheObstacle();
};

class Etoile{
protected:
    int posX, posY, assombrir;
public:
    Etoile();
    void afficheEtoile();
    void depEtoile();
};

class Nuage : public Obstacle {
    int assombrir;
public:
    Nuage();
    virtual void afficheObstacle();
    virtual void depObstacle();
};

class Arbre {
protected:
    int posX;
public:
    Arbre();
    void afficheArbre();
};

class Plateforme : public Obstacle {
public:
    Plateforme();
    virtual void afficheObstacle();
    virtual void depObstacle();
};

#endif //QT_PROJECT_DECOR_H
