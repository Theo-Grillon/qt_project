#include <iostream>
#include "Window.h"
using namespace std;
//#define assombrir rand()
//#define enJeu 0

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    Window test;
    test.show();
    return app.exec();
}