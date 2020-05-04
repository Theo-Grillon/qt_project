//
// Created by Théo on 20/04/2020.
//

#include "Window.h"
using namespace std;

Window::Window(QWidget* parent) : QMainWindow(parent){
    this->decor= new Background();

    QGraphicsView* charView= new QGraphicsView();
    charView->setScene(decor);
    charView->resize(300,300);
    charView->setWindowTitle("Patate-boy");
    charView->show();

    mainView = new QGraphicsView();
    mainView->setScene(decor);
    mainView->scale(0.5,0.5);

    this->setCentralWidget(mainView);
    this->setWindowTitle("Main view");
    this->resize(501,326);
}
