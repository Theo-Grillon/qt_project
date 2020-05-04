//
// Created by Théo on 03/05/2020.
//

#ifndef QT_PROJECT_MENUS_H
#define QT_PROJECT_MENUS_H

#include "utilitaries.h"
#include "Window.h"


class MainMenu : public QWidget{
    Q_OBJECT;
protected:
    QPushButton* new_game;
    QPushButton* leaderboard;
    QPushButton* quit;
    QLabel* background;
public:
    MainMenu(QWidget* = nullptr);
public slots:
    void newGame();
    void printLeaderboard();
};
class VicScreen : public MainMenu {
    Q_OBJECT;
private:
    QLabel* message;
public:
    VicScreen(QWidget* = nullptr);
};
class DeathScreen : public QWidget{
    Q_OBJECT;
private:
    QPushButton* retry;
    QPushButton* quit;
    QLabel* background;
    QLabel* message;
public:
    DeathScreen(QWidget* = nullptr);
public slots:
    void restart();
};

#endif //QT_PROJECT_MENUS_H
