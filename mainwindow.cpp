#include "mainwindow.h"

using namespace std;

QBrush whiteBrush(Qt::white);
QBrush blackBrush(Qt::black);

MainWindow::MainWindow(){
  setFocusPolicy(Qt::StrongFocus);
  
  //View
  scene = new QGraphicsScene();
  view = new QGraphicsView(scene);
  setCentralWidget(view);
  view->setFixedSize(1030, 770);
  //setWindowTitle("myStar");
  setWindowFlags(Qt::WindowTitleHint);
  setWindowTitle("Star by Yunying Tu");
  
  //MenuBar
  mb = new QMenuBar();
  fileMenu = new QMenu( this);
  mb->addMenu(fileMenu);
  QAction *exitAction = new QAction("Exit", this);
  fileMenu->addAction(exitAction);
  connect(exitAction, SIGNAL(triggered()), this, SLOT(handleQuit()));
  setMenuBar(mb);
  
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
  
  //Instructions
  QPixmap insImage("./Information.png");
  Instructions = new QPushButton();
  Instructions->setGeometry(570, 446, 60, 40);
  QPalette InsPalette;
  InsPalette.setBrush(Instructions->backgroundRole(), QBrush(insImage));
  Instructions->setFlat(true);
  Instructions->setAutoFillBackground(true);
  Instructions->setPalette(InsPalette);
  scene->addWidget(Instructions);
  Instruct = new QPixmap("./Instructions.png");
  InsImage = new QGraphicsPixmapItem(*Instruct);
  connect(Instructions, SIGNAL(clicked()), this, SLOT(handleIns()));
  
  //Start Button
  start = new QPushButton("START");
  start->setFont(QFont("Helvatica", 23, 40));
  start->setGeometry(400, 435, 150, 50);
  scene->addWidget(start);
  connect(start, SIGNAL(clicked()), this, SLOT(handleStart()));
  
  //Set Quit Button
  QPixmap quitImage1("./Quit.png");
  quit1 = new QPushButton();
  quit1->setGeometry(950, 20, 55, 55);
  QPalette quitPalette1;
  quitPalette1.setBrush(quit1->backgroundRole(), QBrush(quitImage1));
  quit1->setFlat(true);
  quit1->setAutoFillBackground(true);
  quit1->setPalette(quitPalette1);
  scene->addWidget(quit1);
  connect(quit1, SIGNAL(clicked()), this, SLOT(handleQuit()));
  
  view->show();
  
}

MainWindow::~MainWindow(){}

void MainWindow::handleStart(){

  //Some Initialization
  lifeNum = 3;
  scoreNum = 900;
  checkCar = false;
  checkMoon = false;
  myBombStatus = false;
  myMoonStatus = false;
  myCarStatus = false;
  myBombTime = 0;
  myMoonTime = 0;
  myGirlTime = 0;
  myStarTime = 0;
  level = 1;
  candy_is_here = false;
  myCandyTime = 0;
  candyStatus = false;
  greenStar = new QPixmap("./greenStar.png");
  redStar = new QPixmap ("./redStar.png");
  yellowStar = new QPixmap ("./yellowStar.png");
  blueStar = new QPixmap ("./blueStar.png");
  evilStar = new QPixmap ("./evilStar.png");
  moonImage = new QPixmap("./Moon.png");
  bombImage = new QPixmap("./Bomb.png");
  carImage = new QPixmap("./Car.png");
  candyImage = new QPixmap("./Candy.png");
  candyGirlImage = new QPixmap("./CandyGirl.png");
  
  
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
  
  
  //Set User
  user = new QGraphicsSimpleTextItem("User:");
  user->setFont(QFont("Helvatica", 18, 50));
  user->setBrush(whiteBrush);
  user->setPos(390, 20);
  gamescene->addItem(user);
  //UserName
  userN = new QGraphicsSimpleTextItem ();
  userN->setText(username->text());
  userN->setFont(QFont("Helvatica",20,40,40));
  userN->setBrush(whiteBrush);
  userN->setPos(470, 20);
  gamescene->addItem(userN);
  
  //Set Level
  levelT = new QGraphicsSimpleTextItem("Level:");
  levelT->setFont(QFont("Helvatica", 18, 50));
  levelT->setBrush(whiteBrush);
  levelT->setPos(610, 20);
  gamescene->addItem(levelT);
  //Level
  levelN = new QGraphicsSimpleTextItem (toStr(level).c_str());
  levelN->setFont(QFont("Helvatica",20,40,40));
  levelN->setBrush(whiteBrush);
  levelN->setPos(710, 20);
  gamescene->addItem(levelN);
  
  //Set Pause Button
  QPixmap pauseImage("./Pause.png");
  Pause = new QPushButton();
  Pause->setGeometry(830, 20, 55, 55);
  QPalette PausePalette;
  PausePalette.setBrush(Pause->backgroundRole(), QBrush(pauseImage));
  Pause->setFlat(true);
  Pause->setAutoFillBackground(true);
  Pause->setPalette(PausePalette);
  gamescene->addWidget(Pause);
  connect(Pause, SIGNAL(clicked()), this, SLOT(handlePause()));
  
  //Set Quit Button
  QPixmap quitImage("./Quit.png");
  quit = new QPushButton();
  quit->setGeometry(900, 20, 55, 55);
  QPalette quitPalette;
  quitPalette.setBrush(quit->backgroundRole(), QBrush(quitImage));
  quit->setFlat(true);
  quit->setAutoFillBackground(true);
  quit->setPalette(quitPalette);
  gamescene->addWidget(quit);
  connect(quit, SIGNAL(clicked()), this, SLOT(handleQuit()));
  
  //Bomb
  bomb_show_timer = new QTimer();
  connect(bomb_show_timer, SIGNAL(timeout()), this, SLOT(handleBombShowTimer()));
  bomb_show_timer->start(15000);
  
  //Dropping Stars
  star_show_timer = new QTimer();
  connect(star_show_timer, SIGNAL(timeout()), this, SLOT(handleStarTimer()));
  star_show_timer -> start(10);
  
  
  //Appear Car
  car_show_timer = new QTimer();
  connect(car_show_timer, SIGNAL(timeout()), this, SLOT(handleCarShowTimer()));
  car_show_timer->start(10000);
  
  
  //Moon
  moon_show_timer = new QTimer();
  connect(moon_show_timer, SIGNAL(timeout()), this, SLOT(handleMoonShowTimer()));
  moon_show_timer->start(30000);

  
  //Girl
  girlImage = new QPixmap("./Girl.png");
  myGirl = new Girl(*girlImage);
  gamescene->addItem(myGirl);
  girl_timer = new QTimer();
  connect(girl_timer, SIGNAL(timeout()), this, SLOT(handleGirlTimer()));
  
  setFocus();
}

string MainWindow::toStr(int num){
  stringstream ss;
  ss << num;
  return ss.str();
}

void MainWindow::handleBombShowTimer(){
  int coX = rand() % 300;
  int coY = rand() % 300;
  int Vx = rand() % 3+1;
  int Vy = rand() % 3+1;
  if (level != 1){
    Vx = Vx+2*level;
    Vy = Vy+2*level;
  }
  myBombStatus = true;
  
  myBomb = new Bomb(*bombImage, coX, coY, Vx, Vy);
  bomb_move_timer = new QTimer();
  gamescene->addItem(myBomb);
  connect(bomb_move_timer, SIGNAL(timeout()), this, SLOT(handleBombTimer()));
  bomb_move_timer->start(20);
}
  

void MainWindow::handleBombTimer(){
  myBomb->move(1000, 760);
  myBombTime++;
  if (myBomb->bombClicked){
    myBombTime = 500;
  }
  
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
      if (candyStatus == false){
        lifeNum --;
        checkLife();
      }
      
    }
    setFocus();
  }
}

void MainWindow::handleCarShowTimer(){
  
  int carV = 3+level*2;
  myCar = new Car(*carImage, carV);
  myCarStatus = true;

  gamescene->addItem(myCar);
  car_move_timer = new QTimer();
  connect(car_move_timer, SIGNAL(timeout()), this, SLOT(handleCarTimer()));
  car_move_timer->start(10);
}

void MainWindow::handleCarTimer(){
  myCar->move();
  if (myCar->collidesWithItem(myGirl) && checkCar == false && candyStatus == false){
    scoreNum = scoreNum - 200;
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
  
  myMoonStatus = true;
  int ran = rand() % 700+100;
  myMoon = new Moon(*moonImage, ran);
  gamescene->addItem(myMoon);
  moon_move_timer = new QTimer();
  connect(moon_move_timer, SIGNAL(timeout()), this, SLOT(handleMoonTimer()));
  moon_move_timer->start(10+level*10);
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
  switch (e->key()){
    case Qt::Key_Left:
      myGirl->moveLeft();
      break;
    case Qt::Key_Right:
      myGirl->moveRight();
      break;
    case Qt::Key_Space:
      girlAction();
      break;
    case Qt::Key_A:
      myGirl->moveLeft();
      break;

  }
}

void MainWindow::handleGirlTimer(){
  myGirlTime++;

  if (myGirlTime <= 25) {
    myGirl->jumpU();
    if (myGirlTime == 25){myGirl->vy = 0; }
  }

  
  else if (myGirlTime <= 50){
    myGirl->jumpD();
    if (myGirlTime == 50) {myGirl->vy = 10; }
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
  

  if (myStarTime == 27 + 10*level){
    //setFocus();
    int sx = rand() % 960+10;
    int svy = rand() % 3+1;
    int tm = rand() % (80 + 20*level);
    int color;
    if (tm > 80){
      color = rand() % 5;
    }
    else {color = rand() % 4;}
    switch(color){
      case 0:
        stars.push_back(new Star(*greenStar, sx, svy, 0));
        break;
      
      case 1:
        stars.push_back(new Star(*redStar, sx, svy, 1));
        break;
        
      case 2:
        stars.push_back(new Star(*yellowStar, sx, svy, 2));
        break;
      
      case 3:
        stars.push_back(new Star(*blueStar, sx, svy, 3));
        break;
        
      case 4:
        stars.push_back(new Star(*evilStar, sx, svy, 4));
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
    scoreNum = scoreNum+1000-level*100;
    checkScore();
  }
  
  if (lifeNum == 0){
    lifeN->setText(toStr(lifeNum).c_str());
    string show = "Game Over \n User: " + userN->text().toStdString() + " Score: " + toStr(scoreNum) + "\n Click OK to start again!";
    QMessageBox errorBox(QMessageBox::NoIcon, "GAME OVER! ", show.c_str());
    errorBox.exec();
    handlePause();
    stars.clear();

    view->setScene(scene);
    return;
  }
  else {
    lifeN->setText(toStr(lifeNum).c_str());
  }
  
}
    
void MainWindow::checkScore(){
  if (scoreNum > atoi(scoreN->text().toStdString().c_str())){
    if (scoreNum % 1000 == 0 && candy_is_here == false && candyStatus == false){
      cout << "Score detected" << endl;
      candy_timer = new QTimer();
      candy_timer->start(30);
      connect(candy_timer, SIGNAL(timeout()), this, SLOT(handleCandy()));
    }
  }


  if (scoreNum < 0){
    scoreNum = 0;
    scoreN -> setText(toStr(scoreNum).c_str());
    lifeNum --;
    checkLife();
  }
  else {
    scoreN -> setText(toStr(scoreNum).c_str());
  }
  if (scoreNum < 2000){
    level = 1;
    levelN -> setText(toStr(level).c_str());
  }
  if (scoreNum >= 2000){
    level = 2;
    levelN -> setText(toStr(level).c_str());
  }
  
  if (scoreNum > 5000){
    level = 3;
    levelN -> setText(toStr(level).c_str());
  }
  if (scoreNum > 10000){
    level = 4;
    levelN -> setText(toStr(level).c_str());
  }
}

void MainWindow::checkStar(Star* star){
  if (star->collidesWithItem(myGirl)){
    star->inscreen = false;
    if (star->color != 4){
      scoreNum += 20;
    }
    else {
      if (candyStatus == false){
        scoreNum -= 10;
      }
    }
    checkScore();
  }
}

void MainWindow::handleQuit(){
  QApplication::quit();
}

void MainWindow::handleIns(){
  
  scene->addItem(InsImage);
  back = new QPushButton("Back");
  back->setFont(QFont("Helvatica", 23, 40));
  back->setGeometry(800, 550, 120, 60);
  scene->addWidget(back);
  connect(back, SIGNAL(clicked()), this, SLOT(handleBack()));
}

void MainWindow::handleBack(){
  back->hide();
  scene->removeItem(InsImage);
}

void MainWindow::handleCandy(){
  myCandyTime++;
  
  if (candy_is_here == false){
    myCandy = new Candy(*candyImage, rand()%1000);
    gamescene->addItem(myCandy);
    candy_is_here = true;
  }
  
  else if (myCandy->collidesWithItem(myGirl)){
    myGirl->setPixmap(*candyGirlImage);
    myCandyTime = 100;
    candyS = new QTimer();
    candyS->start(8000);
    connect(candyS, SIGNAL(timeout()), this, SLOT(handleGirlCandy()));
    candyStatus = true;
  }
    
  
  if (myCandyTime >= 100){
    if (candy_is_here == true){
      gamescene->removeItem(myCandy);
      candy_timer -> stop();
      delete candy_timer;
      candy_is_here = false;
      delete myCandy;
      myCandyTime = 0;
    }
  }
}
  
void MainWindow::handleGirlCandy(){

    candyStatus = false;
    candyS->stop();
    delete candyS;
    myGirl->setPixmap(*girlImage); 
}
  
