//
// Created by Théo on 20/04/2020.
//

#ifndef QT_PROJECT_PERSONNAGE_H
#define QT_PROJECT_PERSONNAGE_H

class Personnage {
protected:
    int x, y, lx, ly, rx, ry;
public:
    Personnage();
    void deplacement();
    void dessineJambes();
    void depJambes();
};


#endif //QT_PROJECT_PERSONNAGE_H
