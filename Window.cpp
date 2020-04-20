//
// Created by Théo on 20/04/2020.
//

#include "Window.h"
using namespace std;

Window::Window() {
    vector<shared_ptr<Trou>> t[int(rand() % 4)];
    vector<shared_ptr<Arbre>> a[int(rand() % 3 + 1)];
    vector<shared_ptr<Etoile>> e[int(rand() % 50 + 1)];
    vector<shared_ptr<Nuage>> n[int(rand() % 50 + 1)];
    vector<shared_ptr<Plateforme>> p[int(rand() % 3 + 1)];
    vector<shared_ptr<Obstacle>> o[int(rand() % 3)];
    this->setFixedSize(1000,650);
}