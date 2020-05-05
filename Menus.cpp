//
// Created by Théo on 03/05/2020.
//

#include "Menus.h"

MainMenu::MainMenu(QWidget *parent) : QWidget(parent) {
    //QPixmap bg("mainMenu.png");
    //this->background->setPixmap(bg);

    this->setWindowTitle("Welcome!");
    this->resize(500, 325);
    auto layout = new QVBoxLayout;
    this->new_game = new QPushButton("New Game");
    layout->addWidget(this->new_game);
    this->leaderboard = new QPushButton("Leaderboard");
    layout->addWidget(this->leaderboard);
    this->quit = new QPushButton("Quit Game");
    layout->addWidget(this->quit);
    this->setLayout(layout);

    connect(this->new_game, SIGNAL(clicked()), this, SLOT(newGame()));
    connect(this->leaderboard, SIGNAL(clicked()), this, SLOT(printLeaderboard()));
    connect(this->quit, SIGNAL(clicked()), this, SLOT(close()));
}

void MainMenu::newGame() {
    this->close();
    Window test;
    test.show();
}

void MainMenu::printLeaderboard() {

}

VicScreen::VicScreen(QString time, QWidget * parent) : MainMenu(parent){
    this->setWindowTitle("Victory");
    layout()->removeWidget(leaderboard);
    this->message= new QLabel("You have won !");
    layout()->addWidget(message);
    this->currentTime = new QLabel(time);
    layout()->addWidget(currentTime);
    this->setLayout(layout());
    disconnect(this->leaderboard, SIGNAL(clicked()), this, SLOT(printLeaderboard()));
}

DeathScreen::DeathScreen(QWidget *) {
    this->setWindowTitle("You died !");
    this->resize(1000, 650);
    auto layout = new QVBoxLayout;
    this->message= new QLabel("You are dead !", this);
    layout->addWidget(this->message);
    this->retry = new QPushButton("Retry");
    layout->addWidget(this->retry);
    this->quit = new QPushButton("Quit Game");
    layout->addWidget(this->quit);
    this->setLayout(layout);

    connect(this->retry, SIGNAL(clicked()), this, SLOT(restart()));
    connect(this->quit, SIGNAL(clicked()), this, SLOT(close()));
}

void DeathScreen::restart() {
    this->close();
    Window test;
    test.show();
}