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
    double posX, posY, dep;
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
    double posX, posY, assombrir;
public:
    Etoile();
    void afficheEtoile();
    void depEtoile();
};

class Nuage : public Obstacle {
    double assombrir;
public:
    Nuage();
    virtual void afficheObstacle();
    virtual void depObstacle();
};

class Arbre {
protected:
    double posX;
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
