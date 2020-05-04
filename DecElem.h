//
// Created by Théo on 03/05/2020.
//

#ifndef QT_PROJECT_DECELEM_H
#define QT_PROJECT_DECELEM_H

#include "utilitaries.h"

class Obstacle : public QGraphicsPixmapItem{
protected:
    int dep;
    qreal posX, posY;
public:
    Obstacle(QString imgName);
    qreal getPosX(){return posX;}
    qreal getPosY(){return posY;}

    virtual double getDep(){return dep;}
    void setPosX(qreal x){posX=x;}
    virtual void depObstacle();
};

class Trou : public Obstacle {
public:
    Trou(QString imgName);
};

class Arbre : public QGraphicsPixmapItem {
protected:
    qreal posX;
public:
    Arbre(QString imgName);
    qreal getPosX(){return posX;}
    void setPosX(qreal x){posX=x;}
};

class Plateforme : public Obstacle {
public:
    Plateforme(QString imgName);
    virtual void depObstacle();
};

#endif //QT_PROJECT_DECELEM_H
