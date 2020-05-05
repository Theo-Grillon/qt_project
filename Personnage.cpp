//
// Created by Théo on 20/04/2020.
//

#include "Personnage.h"
#include "Menus.h"
using namespace std;
Personnage::Personnage(QString frameName, int x, int y) : QGraphicsPixmapItem(QPixmap(frameName)){
    this->x=x;
    this->y=y;
    dep=5;
    fallSpeed=1;
    dead=false;
    victorious=false;
}

void Personnage::deplacement(int d) {

    QPointF pos = this->pos();
    dep=d;
    int newX = pos.x() + dep;
    this->setPos(newX, this->pos().y());
}

void Personnage::jump() {
    QPointF pos = this->pos();

    int newY = pos.y() - dep;

    if (newY < this->y-105) {
        dep = 0;
    }

    else{
        dep=5;
    }

    this->setPos(pos.x(), newY);
}

void Personnage::fall() {
    QPointF pos = this->pos();

    int newY = pos.y() + fallSpeed;
    if (!this->falling()) {
        if (newY >= 431) {
            fallSpeed = 0;
        } else {
            fallSpeed = 1;
        }
    }
    else{
        fallSpeed=5;
        if (newY>=this->scene()->height() && !dead){
            dead=true;
            fallSpeed=0;
            auto death=new DeathScreen;
            death->show();
        }
    }

    this->setPos(pos.x(), newY);
}
void Personnage::victory(){
    if (this->pos().x()+34>=951 && !dead){
        victorious=true;
        auto vic= new VicScreen(this->getTime());
        vic->show();
    }
}