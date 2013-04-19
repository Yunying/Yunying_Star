#include "mainwindow.h"

using namespace std;

QBrush whiteBrush(Qt::white);
QBrush blackBrush(Qt::black);

void MainWindow::show(){
  view->show();
}

MainWindow::MainWindow(){
  //Some Initialization
  lifeNum = 0;
  score = 0;

  //View
  scene = new QGraphicsScene();
  view = new QGraphicsView(scene);
  view->setFixedSize(1030, 770);
  view->setWindowTitle("Puzzle Game");
  
  //SetBackground
  QPixmap night("./night.jpg");
  scene->addPixmap(night);
  
  //Twinkle
  twinkle = new QGraphicsSimpleTextItem("Twinkle Twinkle");
  QFont *twinklefont = new QFont("Times", 45);
  twinklefont->setItalic(true);
  twinkle->setFont(*twinklefont);
  twinkle->setBrush(whiteBrush);
  twinkle->setPos(275, 120);
  scene->addItem(twinkle);
  
  //Little Star
  little_star = new QGraphicsSimpleTextItem("Little Star");
  little_star->setFont(QFont("Serif", 70, 20));
  little_star->setBrush(whiteBrush);
  little_star->setPos(240, 200);
  scene->addItem(little_star);
  
  //User Name
  usernametext = new QGraphicsSimpleTextItem("User Name: ");
  usernametext->setFont(QFont("Times", 18, 10, 10));
  usernametext->setBrush(whiteBrush);
  usernametext->setPos(315, 370);
  scene->addItem(usernametext);
  
  //UserName Box
  username = new QLineEdit();
  username->setFont(QFont("Times", 15, 60,10));
  username->setGeometry(455, 370, 200, 40);
  scene->addWidget(username);
  
  //Start Button
  start = new QPushButton("START");
  start->setFont(QFont("Helvatica", 23, 40));
  start->setGeometry(400, 435, 150, 50);
  scene->addWidget(start);
  
  connect(start, SIGNAL(clicked()), this, SLOT(handleStart()));
}

MainWindow::~MainWindow(){}

void MainWindow::handleStart(){
  //Set the new Scene
  gamescene = new QGraphicsScene();
  QPixmap gamenight("./GameNight");
  view->setScene(gamescene);
  gamescene->addPixmap(gamenight);
  
  //Set the life Moon 
  lifeMoon = new QPixmap("./lifemoon.jpg");
  
  
  //Begin a timer
  
  //Dropping Stars
  
  //Appear Bombs
  
  //Appear Car
  
  //Score increase/decrease
  
  //Life

}

void MainWindow::add_life(){
  if (lifeNum == 3){
    score = score + 1000;
  }
  
  else if (lifeNum == 1){
    gamescene->addPixmap(lifeMoon












