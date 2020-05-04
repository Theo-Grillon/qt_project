//
// Created by Théo on 20/04/2020.
//

#ifndef QT_PROJECT_DECOR_H
#define QT_PROJECT_DECOR_H

#include "utilitaries.h"
#include "DecElem.h"
#include "Personnage.h"



class Background : public QGraphicsScene {
    Q_OBJECT;
private:
    QPixmap background;
    QTimer* timer;
    QTimer* charTime;
    QVector<Trou*> holes;
    QVector<Arbre*> trees;
    QVector<Plateforme*> platforms;
    QVector<Obstacle*> obstacles;
    Personnage* personnage;
    Obstacle* arrivee;
    int frame;
    bool gameOver=false;
protected:
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent* event);
public:
    Background();
    void drawBackground(QPainter *painter, const QRectF &rect);

    virtual ~Background();

public slots:
    void update();
    void charUpdate();
};

#endif //QT_PROJECT_DECOR_H
