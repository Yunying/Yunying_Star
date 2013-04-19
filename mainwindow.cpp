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
  scoreNum = 0;
  myBombTime = 0;

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
  //Check if the user has entered a username
  if (username->isModified() == false){
    QMessageBox errorBox(QMessageBox::NoIcon, "ERROR", "Please enter a username!");
    errorBox.exec();
    return;
  }
  
  else{
    name = new QString(username->text());
  }


  //Set the new Scene
  gamescene = new QGraphicsScene();
  QPixmap gamenight("./GameNight");
  view->setScene(gamescene);
  gamescene->addPixmap(gamenight);
  
  //Set Life (INITIALIZATION)
  life = new QGraphicsSimpleTextItem("Life:");
  life->setFont(QFont("Helvatica", 18, 50));
  life->setBrush(whiteBrush);
  life->setPos(30, 20);
  gamescene->addItem(life);
  
  //Set Score (INITIALIZATION)
  score = new QGraphicsSimpleTextItem("Score:");
  score->setFont(QFont("Helvatica", 18, 50));
  score->setBrush(whiteBrush);
  score->setPos(190, 20);
  gamescene->addItem(score);
  
  //Bomb

  bomb_show_timer = new QTimer(this);
  connect(bomb_show_timer, SIGNAL(timeout()), this, SLOT(handleBombShowTimer()));
  bomb_show_timer->start(5000);
  
  //Dropping Stars
  
  //Appear Bombs
  
  //Appear Car
  
  //Score increase/decrease
  
  //Life

}

string MainWindow::toStr(int num){
  stringstream ss;
  ss << num;
  return ss.str();
}

void MainWindow::handleBombShowTimer(){
  QPixmap bombImage("./Bomb.png");
  int coX = rand() % 300;
  int coY = rand() % 300;
  int Vx = rand() % 20;
  int Vy = rand() % 20;
  
  myBomb = new Bomb(bombImage, coX, coY, Vx, Vy);

  gamescene->addItem(myBomb);
  bomb_move_timer = new QTimer(this);
  connect(bomb_move_timer, SIGNAL(timeout()), this, SLOT(handleBombTimer()));
  bomb_move_timer->start(10);
}
  
  


void MainWindow::handleBombTimer(){
  myBomb->move(1000, 760);
  myBombTime++;
  
  //Bomb Disappear
  if (myBombTime == 300){
    gamescene->removeItem(myBomb);
    bomb_move_timer->stop();
    delete bomb_move_timer;
    delete myBomb;
    myBombTime = 0;
  }
}







