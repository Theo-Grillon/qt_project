//
// Created by Théo on 20/04/2020.
//

#ifndef QT_PROJECT_UTILITARIES_H
#define QT_PROJECT_UTILITARIES_H

#include <cmath>
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <memory>
#include <QApplication>
#include <QWidget>

int randomGen(int valFin=1, double valStart=0){
    return int(rand() % valFin + valStart);
}

#endif //QT_PROJECT_UTILITARIES_H
