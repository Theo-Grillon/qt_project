//
// Created by Théo on 20/04/2020.
//

#include "Decor.h"

using namespace std;


Trou::Trou() {
    int r=randomGen(650);
    posX=100+r;
}

Etoile::Etoile() {
    int r1=randomGen(940);
    int r2=randomGen(150);
    posX=10+r1;
    posY=10+r2;
}

Nuage::Nuage() {
    int r1=randomGen(980);
    int r2=randomGen(150);
    int r3=randomGen(2,0.0000000001);
    posX=10+r1;
    posY=10+r2;
    dep=-r3;
}

Arbre::Arbre() {
    int r=randomGen(880);
    posX=60+r;
}

Plateforme::Plateforme() {
    int r1=randomGen(960);
    int r2=randomGen(150);
    int r3=randomGen(10);
    posX=10+r1;
    posY=300+r2;
    do{
        dep= -5 + r3;
    }while (dep == 0);
}

Obstacle::Obstacle() {
    int r1=randomGen(500);
    int r2=randomGen(490);
    int r3=randomGen(10);
    posX=250+r1;
    posY=10+r2;
    do{
        dep= -5 + r3;
    }while (dep == 0);
}

void Etoile::depEtoile() {
    posX-=0.1;
}

void Nuage::depObstacle() {
    posX+=dep;
}

void Plateforme::depObstacle() {
    if (posX<10 || posY>960){
        dep=-dep;
    }
    posX+=dep;
}

void Obstacle::depObstacle() {
    if (dep < 10 || dep > 500){
        dep=-dep;
    }
    posY+=dep;
}

void Trou::afficheObstacle() {
    cout<<"Trou"<<endl;
}

void Nuage::afficheObstacle() {
    cout<<"Nuage"<<endl;
}

void Plateforme::afficheObstacle() {
    cout<<"Plateforme"<<endl;
}
void Obstacle::afficheObstacle() {
    cout<<"Obstacle"<<endl;
}