//
// Created by Théo on 20/04/2020.
//

#include "utilitaries.h"
#include "Decor.h"
#include "Menus.h"

using namespace std;

Background::Background() {
    this->background.load("background.png");
    this->setSceneRect(0,0,background.width(),background.height());
    //Background::bestTime=INFINITY;
    this->timer = new QTimer(this);
    this->timer->start(30);
    this->charTime = new QTimer(this);
    this->charTime->start(500);
    t = new Timer();

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    int nbHoles= qrand() % 4;
    for (int h=0; h<nbHoles; h++){
        this->holes.push_back(new Trou("hole.png"));
    }
    for (int t=0; t<(qrand() % 3 + 1); t++){
        this->trees.push_back(new Arbre("tree.png"));
    }
    for (int p=0; p<nbHoles; p++){
        this->platforms.push_back(new Plateforme("plateforme.png"));
    }
    for (int o=0; o<qrand() % 3; o++){
        this->obstacles.push_back(new Obstacle("obstacle.png"));
    }

    for (int i = 0; i < holes.size(); i++) {

        Trou* hole = this->holes[i];

        this->addItem(hole);

        // all the holes on the right place of the scene
        hole->setPos(hole->getPosX(), 525);
    }
    for (int i = 0; i < trees.size(); i++) {

        Arbre* tree = this->trees[i];
        if (!holes.empty()){
            for (int j = 0; j < holes.size(); j++) {
                while (tree->getPosX() >= holes[i]->getPosX() - 133 && tree->getPosX() <= holes[i]->getPosX() + 110) {
                    tree->setPosX(tree->getPosX() + 20);
                }
            }
        }
        this->addItem(tree);

        // all the trees on the right place of the scene
        tree->setPos(tree->getPosX(), 187);
    }
    for (int i = 0; i < platforms.size(); i++) {

        Plateforme* plat = this->platforms[i];

        this->addItem(plat);
        for (int j=0; j<holes.size(); j++){
            if (plat->getPosX()!=holes[i]->getPosX()){
                plat->setPosX(holes[i]->getPosX());
            }
        }
        // all the platforms on the right place of the scene
        plat->setPos(plat->getPosX(), 450);
    }
    for (int i = 0; i < obstacles.size(); i++) {

        Obstacle* obs = this->obstacles[i];

        this->addItem(obs);

        // all the obstacles on the right place of the scene
        obs->setPos(obs->getPosX(), 471);
    }
    frame=0;
    arrivee=new Obstacle("arrivee.png");
    this->addItem(arrivee);
    arrivee->setPos(951,450);
    personnage= new Personnage("hero-frame2.png");
    this->addItem(personnage);
    personnage->setPos(personnage->getPosX(), personnage->getPosY());

}

void Background::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);
    painter->drawPixmap(QRectF(0,0,background.width(), background.height()), background, sceneRect());
}

void Background::update() {

    int nbPlat = platforms.size();
    t->increase();
    for (int i = 0; i < nbPlat; i++) {

        Plateforme* plat = this->platforms[i];

        plat->depObstacle();

        // view update
        QGraphicsView * view = this->views().at(0);
        view->centerOn(plat);
    }
    for (int i=0; i<platforms.size(); i++){
            if(this->personnage->pos().y() <= 360 && this->personnage->pos().x() + 34 >= platforms[i]->getPosX() && this->personnage->pos().x()<=platforms[i]->getPosX()+109){
                    this->personnage->onPlat(true);
                    this->personnage->setPlatId(i);
                    break;
            }
            else{
                this->personnage->onPlat(false);
            }
    }
    for (auto & hole : holes){
        this->personnage->fell(this->personnage->pos().x() + 34 >= hole->getPosX() &&
                               (!this->personnage->getOnPlat() || !this->personnage->jumper()) && this->personnage->pos().y()>=380 && this->personnage->pos().x()+34<=hole->getPosX()+175);
    }
    for (auto & obs : obstacles){
        this->personnage->died(this->personnage->pos().x() + 34 >= obs->getPosX() &&
                               !this->personnage->jumper() && this->personnage->pos().x()+34<=obs->getPosX()+17 && personnage->pos().y()>=380);
    }
    if (this->personnage->getOnPlat()){
        this->personnage->deplacement(-platforms[personnage->getPlatid()]->getDep());
        if (personnage->pos().y()<=350){
            personnage->fall();
        }
        this->personnage->fell(false);
    }
    if ((this->personnage->getPosY()<440 && !this->personnage->getOnPlat() && !this->personnage->jumper()) || this->personnage->falling()){
        this->personnage->fall();
    }
    if (this->personnage->getStatus() && !gameOver){
        gameOver=true;
        auto death=new DeathScreen;
        death->show();
    }
    QGraphicsView* view = this->views().at(0);
    view->centerOn(personnage);
    if (!gameOver) {
        if (personnage->getVic()){
            gameOver=true;
        }
        this->personnage->setTime(t->getTime()/1000);
        personnage->victory();
    }
}
void Background::charUpdate() {
    if (frame%4==0){
        frame+=1;
        QPixmap newFrame("hero-frame1.png");
        personnage->setPixmap(newFrame);
        QGraphicsView * view = this->views().at(0);
        view->centerOn(personnage);
    }
    else if (frame%2==0){
        QPixmap newFrame("hero-frame3.png");
        personnage->setPixmap(newFrame);
        frame+=1;
        QGraphicsView * view = this->views().at(0);
        view->centerOn(personnage);
    }
    else{
        QPixmap newFrame("hero-frame2.png");
        personnage->setPixmap(newFrame);
        frame+=1;
        QGraphicsView * view = this->views().at(0);
        view->centerOn(personnage);
    }
}

void Background::keyPressEvent(QKeyEvent *event) {
    connect(charTime,SIGNAL(timeout()),this,SLOT(charUpdate()));
    if (event->key()==Qt::Key_Right){
        this->personnage->deplacement(5);
    }
    if (event->key()==Qt::Key_Left){
        this->personnage->deplacement(-5);
    }
    if (event->key()==Qt::Key_Up && !personnage->falling()){
        this->personnage->jump();
        this->personnage->jumping(true);
    }
}

Background::~Background(){
    for (Arbre* tree : this->trees){
        delete tree;
    }
    for (Trou* hole : this->holes){
        delete hole;
    }
    for (Obstacle* obs : this->obstacles){
        delete obs;
    }
    for (Plateforme* pl : this->platforms){
        delete pl;
    }
}

void Background::keyReleaseEvent(QKeyEvent *event) {
    QGraphicsScene::keyReleaseEvent(event);
    this->personnage->jumping(false);
    disconnect(charTime,SIGNAL(timeout()),this,SLOT(charUpdate()));
}
