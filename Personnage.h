//
// Created by Théo on 20/04/2020.
//

#ifndef QT_PROJECT_PERSONNAGE_H
#define QT_PROJECT_PERSONNAGE_H

#include "utilitaries.h"
using namespace std;
class Personnage : public QGraphicsPixmapItem{
protected:
    qreal x, y;
    int dep, fallSpeed, platId;
    bool isOnPlat, isJumping, canFall, dead, victorious;
    double time;
public:
    Personnage(QString frameName, int x=20, int y=431);
    void deplacement(int d);
    void jump();
    void fall();
    QString getTime(){return QString::number(time);}
    void setTime(double t){time=t;}
    bool getStatus(){return dead;}
    void setPlatId(int i){platId=i;}
    int getPlatid(){return platId;}
    qreal getPosX(){return x;}
    qreal getPosY(){return y;}
    bool getOnPlat(){return isOnPlat;}
    bool jumper(){return isJumping;}
    bool falling(){return canFall;}
    void jumping(bool b){isJumping=b;}
    void onPlat(bool b){isOnPlat=b;}
    void fell(bool b){canFall=b;}
    void died(bool b){dead=b;}
    void victory();
    bool getVic(){return victorious;}
};


#endif //QT_PROJECT_PERSONNAGE_H
