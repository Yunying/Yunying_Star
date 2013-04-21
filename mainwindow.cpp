#include "mainwindow.h"

using namespace std;

QBrush whiteBrush(Qt::white);
QBrush blackBrush(Qt::black);

void MainWindow::show(){
  view->show();
}

MainWindow::MainWindow(){
  //Some Initialization
  lifeNum = 3;
  scoreNum = 0;
  myBombTime = 0;
  myMoonTime = 0;
  myGirlTime = 0;
  myStarTime = 0;
  myBombStatus = false;
  myMoonStatus = false;
  myCarStatus = false;
  setFocus();
  
  //Music
  

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
  //Some Initialization
  lifeNum = 3;
  scoreNum = 0;
  checkCar = false;
  checkMoon = false;
  myBombStatus = false;
  myMoonStatus = false;
  myCarStatus = false;
  myBombTime = 0;
  myMoonTime = 0;
  myGirlTime = 0;
  myStarTime = 0;
  setFocus();
  
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
  //Life Number
  lifeN = new QGraphicsSimpleTextItem(toStr(lifeNum).c_str());
  lifeN->setFont(QFont("Helvatica", 20, 40, 40));
  lifeN->setBrush(whiteBrush);
  lifeN->setPos(100, 20);
  gamescene->addItem(lifeN);
  
  //Set Score (INITIALIZATION)
  score = new QGraphicsSimpleTextItem("Score:");
  score->setFont(QFont("Helvatica", 18, 50));
  score->setBrush(whiteBrush);
  score->setPos(190, 20);
  gamescene->addItem(score);
  //Score Number
  scoreN = new QGraphicsSimpleTextItem (toStr(scoreNum).c_str());
  scoreN->setFont(QFont("Helvatica",20,40,40));
  scoreN->setBrush(whiteBrush);
  scoreN->setPos(290, 20);
  gamescene->addItem(scoreN);
  
  //Set Pause Button
  QPixmap pauseImage("./Pause.png");
  Pause = new QPushButton();
  Pause->setGeometry(900, 20, 70, 40);
  QPalette PausePalette;
  PausePalette.setBrush(Pause->backgroundRole(), QBrush(pauseImage));
  Pause->setFlat(true);
  Pause->setAutoFillBackground(true);
  Pause->setPalette(PausePalette);
  gamescene->addWidget(Pause);
  connect(Pause, SIGNAL(clicked()), this, SLOT(handlePause()));
  
  //Bomb
  bomb_show_timer = new QTimer(this);
  connect(bomb_show_timer, SIGNAL(timeout()), this, SLOT(handleBombShowTimer()));
  bomb_show_timer->start(10000);
  
  //Dropping Stars
  star_show_timer = new QTimer(this);
  connect(star_show_timer, SIGNAL(timeout()), this, SLOT(handleStarTimer()));
  star_show_timer -> start(10);
  
  
  //Appear Car
  car_show_timer = new QTimer(this);
  connect(car_show_timer, SIGNAL(timeout()), this, SLOT(handleCarShowTimer()));
  car_show_timer->start(10000);
  
  
  //Moon
  moon_show_timer = new QTimer(this);
  connect(moon_show_timer, SIGNAL(timeout()), this, SLOT(handleMoonShowTimer()));
  moon_show_timer->start(13000);

  
  //Girl
  QPixmap girlImage("./Girl.png");
  myGirl = new Girl(girlImage);
  gamescene->addItem(myGirl);
  girl_timer = new QTimer(this);
  connect(girl_timer, SIGNAL(timeout()), this, SLOT(handleGirlTimer()));

  
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
  int Vx = rand() % 3+2;
  int Vy = rand() % 3+2;
  myBombStatus = true;
  
  myBomb = new Bomb(bombImage, coX, coY, Vx, Vy, this);
  bomb_move_timer = new QTimer(this);
  gamescene->addItem(myBomb);
  connect(bomb_move_timer, SIGNAL(timeout()), this, SLOT(handleBombTimer()));
  bomb_move_timer->start(10);
}
  

void MainWindow::handleBombTimer(){
  myBomb->move(1000, 760);
  myBombTime++;
  
  //Bomb Disappear
  if (myBombTime >= 400){
    if (myBombTime > 490){
      gamescene->removeItem(myBomb);
      bomb_move_timer->stop();
      delete bomb_move_timer;
      delete myBomb;
      myBombTime = 0;
      myBombStatus = false;
    }
    
    else {
      gamescene->removeItem(myBomb);
      bomb_move_timer->stop();
      delete bomb_move_timer;
      delete myBomb;
      myBombTime = 0;
      myBombStatus = false;
      
      lifeNum --;
      checkLife();
      
    }
  }
}

void MainWindow::handleCarShowTimer(){
  QPixmap carImage("./Car.png");
  myCar = new Car(carImage, 5);
  myCarStatus = true;

  gamescene->addItem(myCar);
  car_move_timer = new QTimer(this);
  connect(car_move_timer, SIGNAL(timeout()), this, SLOT(handleCarTimer()));
  car_move_timer->start(10);
}

void MainWindow::handleCarTimer(){
  myCar->move();
  if (myCar->collidesWithItem(myGirl) && checkCar == false){
    scoreNum = scoreNum - 300;
    checkScore();
    checkCar = true;
  }
    
  
  if (myCar->carStatus){
    gamescene->removeItem(myCar);
    car_move_timer->stop();
    delete car_move_timer;
    delete myCar;
    myCarStatus = false;
    checkCar = false;
  }
}

void MainWindow::handleMoonShowTimer(){
  QPixmap moonImage("./Moon.png");
  myMoonStatus = true;
  int ran = rand() % 700+100;
  myMoon = new Moon(moonImage, ran);
  gamescene->addItem(myMoon);
  moon_move_timer = new QTimer(this);
  connect(moon_move_timer, SIGNAL(timeout()), this, SLOT(handleMoonTimer()));
  moon_move_timer->start(20);
}

void MainWindow::handleMoonTimer(){
  myMoonTime++;
  if (myMoon->collidesWithItem(myGirl) && checkMoon == false){
    checkMoon = true;
    myMoonTime = 550;
    lifeNum++;
    checkLife();
  }
  
  if (myMoonTime <= 200){
    myMoon->come();
  }
  
  else if (myMoonTime >200 && myMoonTime <= 350){
  }
  
  else if (myMoonTime > 350 && myMoonTime < 550){
    myMoon->leave();
  } 
  
  else{
    gamescene->removeItem(myMoon);
    moon_move_timer->stop();
    delete moon_move_timer;
    delete myMoon;
    myMoonTime = 0;
    myMoonStatus = false;
    checkMoon = false;
  }
}
  
void MainWindow::keyPressEvent(QKeyEvent *e) {
  cout << "clicked" << endl;
  switch (e->key()){
    case Qt::Key_Left:
      myGirl->moveLeft();
      break;
    case Qt::Key_Right:
      myGirl->moveRight();
      break;
    case Qt::Key_Escape:
      QApplication::quit();
      break;
    case Qt::Key_Space:
      girlAction();
      break;
    case Qt::Key_A:
      cout << "Got you" << endl;
      break;
  }
}

void MainWindow::handleGirlTimer(){
  myGirlTime++;
  if (myGirlTime <= 100){
  }
  
  else if (myGirlTime <= 125) {
    myGirl->jumpU();
    if (myGirlTime == 125){myGirl->vy = 0; }
  }

  
  else if (myGirlTime <= 150){
    myGirl->jumpD();
    if (myGirlTime == 150) {myGirl->vy = 10; }
  }

  else{
    myGirlTime = 0;
    girl_timer -> stop();
  }
}
  
void MainWindow::girlAction(){
  girl_timer->start(20);
  
} 

void MainWindow::handleStarTimer(){
  myStarTime++;
  unsigned int starCount = 0;
  while (starCount < stars.size()){
    if (stars[starCount]->inscreen){
      stars[starCount]->move();
      checkStar(stars[starCount]);
      starCount++;
    }
    
    else {
      gamescene->removeItem(stars[starCount]);
      stars.erase(stars.begin() + starCount);
    }
  }
  
  
  QPixmap greenStar("./greenStar.png");
  QPixmap redStar("./redStar.png");
  QPixmap yellowStar("./yellowStar.png");
  QPixmap blueStar("./blueStar.png");
  
  if (myStarTime == 50){
    int sx = rand() % 960+10;
    int svy = rand() % 3+1;
    int color = rand() % 4;
    switch(color){
      case 0:
        stars.push_back(new Star(greenStar, sx, svy));
        break;
      
      case 1:
        stars.push_back(new Star(redStar, sx, svy));
        break;
        
      case 2:
        stars.push_back(new Star(yellowStar, sx, svy));
        break;
      
      case 3:
        stars.push_back(new Star(blueStar, sx, svy));
        break;
     }
     
     gamescene->addItem(stars.back());
     myStarTime = 0;
  }
}

void MainWindow::handlePause(){

  if (star_show_timer->isActive()) {
	star_show_timer->stop();
	bomb_show_timer->stop();
	moon_show_timer->stop();
	car_show_timer->stop();
	if (myCarStatus){
	  car_move_timer->stop();
	}
	if (myBombStatus){
	  bomb_move_timer->stop();
	}
	if (myMoonStatus){
	  myMoonTime = 550;
	}
	
  }
  else {
	star_show_timer->start();
	bomb_show_timer->start();
	moon_show_timer->start();
	car_show_timer->start();
	if (myCarStatus){
	  car_move_timer->start();
	}
	if (myBombStatus){
	  bomb_move_timer->start();
	}
  }

}     
  
void MainWindow::checkLife(){
  if (lifeNum > 3){
    lifeNum = 3;
    scoreNum = scoreNum+1000;
    checkScore();
  }
  
  if (lifeNum == 0){
    lifeN->setText(toStr(lifeNum).c_str());
    QMessageBox errorBox(QMessageBox::NoIcon, "GAME OVER", "GAME OVER! Click OK to Start Again");
    errorBox.exec();
    handlePause();
    stars.clear();
    if (myCarStatus){
	  delete myCar;
	}
	if (myBombStatus){
	  delete myBomb;
	}
	if (myMoonStatus){
	  delete myMoon;
	}
    view->setScene(scene);
    return;
  }
  else {
    lifeN->setText(toStr(lifeNum).c_str());
  }
  
}
    
void MainWindow::checkScore(){
  if (scoreNum < 0){
    scoreNum = 0;
    scoreN -> setText(toStr(scoreNum).c_str());
    lifeNum --;
    checkLife();
  }
  else {
    scoreN -> setText(toStr(scoreNum).c_str());
  }
}

void MainWindow::checkStar(Star* star){
  //Still need to add green Star condition
  if (star->collidesWithItem(myGirl)){
    star->inscreen = false;
    scoreNum += 20;
    checkScore();
  }
}


