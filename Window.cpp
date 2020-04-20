//
// Created by Théo on 20/04/2020.
//

#include "Window.h"
using namespace std;

Window::Window() {
    vector<shared_ptr<Trou>> t[randomGen(4)];
    vector<shared_ptr<Arbre>> a[randomGen(3,1)];
    vector<shared_ptr<Etoile>> e[randomGen(50,1)];
    vector<shared_ptr<Nuage>> n[randomGen(50,1)];
    vector<shared_ptr<Plateforme>> p[randomGen(3,1)];
    vector<shared_ptr<Obstacle>> o[randomGen(3)];
    this->setFixedSize(1000,650);
    this->show();
}