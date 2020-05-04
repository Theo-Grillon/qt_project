//
// Created by Théo on 20/04/2020.
//
#ifndef QT_PROJECT_WINDOW_H
#define QT_PROJECT_WINDOW_H
#include "Decor.h"

class Window : public QMainWindow {
    Q_OBJECT
private:
    Background* decor;
    QGraphicsView* mainView;
public:
    Window(QWidget* parent=nullptr);
};


#endif //QT_PROJECT_WINDOW_H
