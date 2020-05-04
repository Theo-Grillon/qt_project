#include <iostream>
#include "Menus.h"
using namespace std;
//#define enJeu 0

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    MainMenu* m = new MainMenu();
    m->show();
    //Window test;
    //test.show();
    return app.exec();
}