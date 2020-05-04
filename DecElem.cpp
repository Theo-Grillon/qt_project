//
// Created by Théo on 03/05/2020.
//

#include "DecElem.h"

using namespace std;

Trou::Trou(QString imgName) : Obstacle(imgName) {
    int r=int(rand() % 650);
    posX=100+r;
}

Arbre::Arbre(QString imgName) : QGraphicsPixmapItem(QPixmap(imgName)) {
    int r=int(rand() % 880);
    posX=60+r;
}

Plateforme::Plateforme(QString imgName) : Obstacle(imgName) {
    int r1=int(rand() % 960);
    int r2=int(rand() % 150);
    int r3=int(rand() % 10);
    posX=10+r1;
    posY=300+r2;
    do{
        dep= -5 + r3;
    }while (dep == 0);
}

Obstacle::Obstacle(QString imgName) : QGraphicsPixmapItem(QPixmap(imgName)) {
    int r1=int(rand() % 500);
    int r2=int(rand() % 490);
    int r3=int(rand() % 10);
    posX=250+r1;
    posY=10+r2;
}

void Plateforme::depObstacle() {
    QPointF pos = this->pos();

    int newX = pos.x() - dep;

    if (newX < this->posX-30) {
        dep = -dep;
    }

    if (newX > this->posX+55) {
        dep = qrand()% dep + 1;
    }

    this->setPos(newX, pos.y());
}

void Obstacle::depObstacle() {

}
