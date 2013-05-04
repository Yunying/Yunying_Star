#include "mainwindow.h"

using namespace std;

QBrush whiteBrush(Qt::white);
QBrush blackBrush(Qt::black);

/** @brief Set up the Start Screen */
MainWindow::MainWindow(){
  setFocusPolicy(Qt::StrongFocus);
  gamenight2 = new QPixmap("./GameNight2");
  gamenight3 = new QPixmap("./GameNight3");
  gamenight4 = new QPixmap("./GameNight4");
  //Read highest score file
  ifstream ifile("highscore.txt");
  ifile >> scorecount;
  string garbage;
  getline(ifile, garbage);
  int in;
  string names;
  started = false;
  
  for (int i=0; i<scorecount; i++){
    ifile >> names;
    ifile >> in;
    filenames.push_back(names);
    filescores.push_back(in);
  }
  
  if (scorecount == 0){
    filescores.push_back(0);
    filenames.push_back("User");
  }
  ifile.close();
  
  //View
  scene = new QGraphicsScene();
  view = new QGraphicsView(scene);
  setCentralWidget(view);
  view->setFixedSize(1030, 770);
  setWindowTitle("Star by Yunying Tu");
  
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
  
  //Show the view
  view->show(); 
}

MainWindow::~MainWindow(){}

/** @brief Set up the game scene, initialize game values and start timers */
void MainWindow::handleStart(){

  //Some Initialization
  started = true;
  lifeNum = 3;
  scoreNum = 0;
  highscore = 0;
  checkCar = false;
  checkMoon = false;
  myBombStatus = false;
  myMoonStatus = false;
  myCarStatus = false;
  myBombTime = 0;
  myMoonTime = 0;
  myGirlTime = 0;
  myStarTime = 0;
  bombShow = 1;
  moonShow = 5;
  carShow = 1;
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
  gamenight = new QPixmap("./GameNight");
  view->setScene(gamescene);
  gamescene->addPixmap(*gamenight);

  //Set Life (INITIALIZATION)
  life = new QGraphicsSimpleTextItem("Life:");
  life->setFont(QFont("Helvatica", 18, 50));
  life->setBrush(whiteBrush);
  life->setPos(30, 20);
  gamescene->addItem(life);
  life->setZValue(10);
  //Life Number
  lifeN = new QGraphicsSimpleTextItem(toStr(lifeNum).c_str());
  lifeN->setFont(QFont("Helvatica", 20, 40, 40));
  lifeN->setBrush(whiteBrush);
  lifeN->setPos(100, 20);
  gamescene->addItem(lifeN);
  lifeN->setZValue(10);
  
  //Set Score (INITIALIZATION)
  score = new QGraphicsSimpleTextItem("Score:");
  score->setFont(QFont("Helvatica", 18, 50));
  score->setBrush(whiteBrush);
  score->setPos(190, 20);
  gamescene->addItem(score);
  score->setZValue(10);
  //Score Number
  scoreN = new QGraphicsSimpleTextItem (toStr(scoreNum).c_str());
  scoreN->setFont(QFont("Helvatica",20,40,40));
  scoreN->setBrush(whiteBrush);
  scoreN->setPos(290, 20);
  gamescene->addItem(scoreN);
  scoreN->setZValue(10);
  
  
  //Set User
  user = new QGraphicsSimpleTextItem("User:");
  user->setFont(QFont("Helvatica", 18, 50));
  user->setBrush(whiteBrush);
  user->setPos(390, 20);
  gamescene->addItem(user);
  user->setZValue(10);
  //UserName
  userN = new QGraphicsSimpleTextItem ();
  userN->setText(username->text());
  userN->setFont(QFont("Helvatica",20,40,40));
  userN->setBrush(whiteBrush);
  userN->setPos(470, 20);
  gamescene->addItem(userN);
  userN->setZValue(10);
  
  //Set Level
  levelT = new QGraphicsSimpleTextItem("Level:");
  levelT->setFont(QFont("Helvatica", 18, 50));
  levelT->setBrush(whiteBrush);
  levelT->setPos(610, 20);
  gamescene->addItem(levelT);
  levelT->setZValue(10);
  //Level
  levelN = new QGraphicsSimpleTextItem (toStr(level).c_str());
  levelN->setFont(QFont("Helvatica",20,40,40));
  levelN->setBrush(whiteBrush);
  levelN->setPos(710, 20);
  gamescene->addItem(levelN);
  levelN->setZValue(10);
  
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
  
  //Restart Button
  QPixmap restartImage("./Restart.png");
  restart = new QPushButton();
  restart->setGeometry(760, 20, 55, 55);
  QPalette restartPalette;
  restartPalette.setBrush(restart->backgroundRole(), QBrush(restartImage));
  restart->setFlat(true);
  restart->setAutoFillBackground(true);
  restart->setPalette(restartPalette);
  gamescene->addWidget(restart);
  connect(restart, SIGNAL(clicked()), this, SLOT(handleRestart()));
  
  //Timers
  timers = new QTimer();
  timers->start(5000);
  connect(timers, SIGNAL(timeout()),this, SLOT(handleTimers()));
  
  //Dropping Stars
  star_show_timer = new QTimer();
  connect(star_show_timer, SIGNAL(timeout()), this, SLOT(handleStarTimer()));
  star_show_timer -> start(10);
  
  //Girl
  girlImage = new QPixmap("./Girl.png");
  myGirl = new Girl(*girlImage);
  gamescene->addItem(myGirl);
  girl_timer = new QTimer();
  connect(girl_timer, SIGNAL(timeout()), this, SLOT(handleGirlTimer()));
  
  setFocus();
}

/** @brief Convert int to string */
string MainWindow::toStr(int num){
  stringstream ss;
  ss << num;
  return ss.str();
}

/** @brief Control the appearance of bomb, moon and car */
void MainWindow::handleTimers(){
  moonShow++;
  carShow++;
  bombShow++;
  
  //Control the intervals of different objects
  //Everytime the number reaches the pre-set interval, an object shows in the screen
  //(The timer that controls that object starts)
  if (moonShow == 8){
    handleMoonShowTimer();
    moonShow = 0;
  }
  
  if (carShow == 3){
    handleCarShowTimer();
    carShow = 0;
  }
  
  if (bombShow == 5){
    handleBombShowTimer();
    bombShow = 0;
  }
}
  
/** @brief Control the initial status of the bomb */
void MainWindow::handleBombShowTimer(){
  //Set the initial velocity and position of the bomb
  int coX = rand() % 300;
  int coY = rand() % 300;
  int Vx = rand() % 3+1;
  int Vy = rand() % 3+1;
  if (level != 1){
    Vx = Vx+2*level;
    Vy = Vy+2*level;
  }
  myBombStatus = true;
  
  //Start the timer that controls the bomb's moving
  myBomb = new Bomb(*bombImage, coX, coY, Vx, Vy);
  bomb_move_timer = new QTimer();
  gamescene->addItem(myBomb);
  connect(bomb_move_timer, SIGNAL(timeout()), this, SLOT(handleBombTimer()));
  bomb_move_timer->start(20);
}
  
/** @brief Control the bomb's moving */
void MainWindow::handleBombTimer(){
  myBomb->move(1000, 760);
  myBombTime++;
  
  //Bomb disappears after sevral seconds
  if (myBomb->bombClicked){
    myBombTime = 500;
  }
  
  //Bomb Disappear
  //If bomb is clicked, the myBombTime will be set up as 500, so life will not be deducted
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

/** @brief Control the initial status of the car */
void MainWindow::handleCarShowTimer(){
  //Initialize the car status
  int carV = 3+level*2;
  myCar = new Car(*carImage, carV);
  myCarStatus = true;

  gamescene->addItem(myCar);
  car_move_timer = new QTimer();
  connect(car_move_timer, SIGNAL(timeout()), this, SLOT(handleCarTimer()));
  car_move_timer->start(12);
}

/** @brief Control the car's moving */
void MainWindow::handleCarTimer(){
  myCar->move();
  //If the car collides with the girl, than some points will be deducted
  if (myCar->collidesWithItem(myGirl) && checkCar == false && candyStatus == false){
    scoreNum = scoreNum - (300*level);
    checkScore();
    checkCar = true;
  }
    
  //The car will be removed after it goes out of the screen
  if (myCar->carStatus){
    gamescene->removeItem(myCar);
    car_move_timer->stop();
    delete car_move_timer;
    delete myCar;
    myCarStatus = false;
    checkCar = false;
  }
}

/** @brief Control the initial status of the moon */
void MainWindow::handleMoonShowTimer(){
  myMoonStatus = true;
  int ran = rand() % 700+100;
  myMoon = new Moon(*moonImage, ran, myGirl);
  gamescene->addItem(myMoon);
  moon_move_timer = new QTimer();
  connect(moon_move_timer, SIGNAL(timeout()), this, SLOT(handleMoonTimer()));
  moon_move_timer->start(20);
}

/** @brief Handle the moving of the moon */
void MainWindow::handleMoonTimer(){
  myMoonTime++;
  //If the girl gets the moon, she will have one more life
  if (myMoon->collidesWithItem(myGirl) && checkMoon == false){
    checkMoon = true;
    myMoonTime = 550;
    lifeNum++;
    checkLife();
  }
  
  //The moon's moving route
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

/** @brief Receive keyboard signals and move the girl accordingly*/
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
    case Qt::Key_W:
      girlAction();
      break;
    case Qt::Key_A:
      myGirl->moveLeft();
      break;
    case Qt::Key_D:
      myGirl->moveRight();
      break;

  }
}

/** @brief Control the jump action of the girl */
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

/** @brief Start the girl's action */
void MainWindow::girlAction(){
  girl_timer->start(20);
  
} 

/** @brief Control the star's appearance and moving */
void MainWindow::handleStarTimer(){
  myStarTime++;
  unsigned int starCount = 0;
  //Move the star; Check if the star is still in the screen
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
  
  //Stars appear at different frequency at different levels
  if (myStarTime == 25){
    int sx = rand() % 960+10;
    int svy = rand() % 3+2*level-1;
    int tm = rand() % (80 + 20*level);
    int color;
    if (tm > 80){
      color = rand() % 5;
    }
    //Four colors of stars randomly appears
    else {color = rand() % 4;}
    switch(color){
      case 0:
        stars.push_back(new Star(*greenStar, sx, svy, 0, myGirl));
        break;
      
      case 1:
        stars.push_back(new Star(*redStar, sx, svy, 1, myGirl));
        break;
        
      case 2:
        stars.push_back(new Star(*yellowStar, sx, svy, 2, myGirl));
        break;
      
      case 3:
        stars.push_back(new Star(*blueStar, sx, svy, 3, myGirl));
        break;
        
      case 4:
        stars.push_back(new Star(*evilStar, sx, svy, 4, myGirl));
        break;
     }
     
     gamescene->addItem(stars.back());
     myStarTime = 0;
  }
}

/** @brief Stop all timers */
void MainWindow::handlePause(){

  if (star_show_timer->isActive()) {
    timers->stop();
	star_show_timer->stop();
	if (myCarStatus){
	  car_move_timer->stop();
	}
	if (myBombStatus){
	  bomb_move_timer->stop();
	}
	if (myMoonStatus){
	  moon_move_timer->stop();
	}
	if (candyStatus){
	  candyS->stop();
	}
	
  }
  else {
    setFocus();
	star_show_timer->start();
	timers->start();
	if (myCarStatus){
	  car_move_timer->start();
	}
	if (myBombStatus){
	  bomb_move_timer->start();
	}
	if (myMoonStatus){
	  moon_move_timer->start();
	}
	if (candyStatus){
	  candyS->start();
	}
  }

}     

/** @brief Check if the game ends and update the lifeNumber in the scene*/ 
void MainWindow::checkLife(){
  if (lifeNum > 3){
    lifeNum = 3;
    scoreNum = scoreNum+700;
    checkScore();
  }
  
  if (lifeNum == 0){
    lifeN->setText(toStr(lifeNum).c_str());
    string show = "Game Over \n User: " + userN->text().toStdString() + " Score: " + toStr(scoreNum) + "\n Click OK to start again!";
    QMessageBox errorBox(QMessageBox::NoIcon, "GAME OVER! ", show.c_str());
    errorBox.exec();
    //handleRestart();
    handlePause();
    stars.clear();
    delete timers;
    delete star_show_timer;
    view->setScene(scene);
    return;
  }
  else {
    lifeN->setText(toStr(lifeNum).c_str());
  }
  
}

/** @brief Check the score to see if should change the lifeNum or level */   
void MainWindow::checkScore(){
  if (scoreNum > highscore){
    highscore = scoreNum;
  }

  if (scoreNum > atoi(scoreN->text().toStdString().c_str())){
    if (scoreNum % 1000 == 0 && candy_is_here == false && candyStatus == false){
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
  int Tlevel = level;
  if (scoreNum < 400){
    Tlevel = 1;
  }
  if (scoreNum >= 400){
    Tlevel = 2;
  }
  
  if (scoreNum > 1000){
    Tlevel = 3;
  }
  if (scoreNum > 4000){
    Tlevel = 4;
  }
  
  if (Tlevel > level){
    level = Tlevel;
    levelN -> setText(toStr(level).c_str());
    //Change Background
    if (level == 2){
      gamescene->addPixmap(*gamenight2);
    }
    
    if (level == 3){
      gamescene->addPixmap(*gamenight3);
    }
    
    if (level == 4){
      gamescene->addPixmap(*gamenight4);
    }
  }

}

/** @brief Check if the star collides with the girl */
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

/** @brief Quit */
void MainWindow::handleQuit(){
 if (started){
  bool modified = false;
  for (unsigned int i=0; i<filescores.size(); i++){
    if (highscore > filescores[i]){
      if (scorecount != 0){
        filescores.push_back(0);
        filenames.push_back("User");
      }
      for (unsigned int j=filescores.size()-1; j>i; j--){
        filescores[j] = filescores[j-1];
        filenames[j] = filenames[j-1];
      }
      filescores[i] = highscore;
      filenames[i] = name->toStdString();
      modified = true;
      break;
    }
  }
  if (!modified){
    filescores.push_back(highscore);
    filenames.push_back(name->toStdString());
  }
  
  ofstream ofile("highscore.txt");
  ofile << ++scorecount << " scores saved" << endl;
  ofile << endl;
  for (unsigned int i=0; i<filescores.size(); i++){
    ofile << setw(7) << filenames[i] << setw(7) << filescores[i] << endl;
  }
  
  ofile.close();
 }
  
  QApplication::quit();
}

/** @brief Set up the instructions */
void MainWindow::handleIns(){
  
  scene->addItem(InsImage);
  back = new QPushButton("Back");
  back->setFont(QFont("Helvatica", 23, 40));
  back->setGeometry(800, 50, 120, 60);
  scene->addWidget(back);
  connect(back, SIGNAL(clicked()), this, SLOT(handleBack()));
}

/** @brief Go back to the start screen from the instruction page */
void MainWindow::handleBack(){
  back->hide();
  scene->removeItem(InsImage);
}

/** @brief Monitor the candy's status on the screen */
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

/** @brief Handle the Girl's in the candyStatus */
void MainWindow::handleGirlCandy(){
    candyStatus = false;
    candyS->stop();
    delete candyS;
    myGirl->setPixmap(*girlImage); 
}
  

/** @breif Restart the game */
void MainWindow::handleRestart(){
    timers->stop();
    delete timers;
	star_show_timer->stop();
	delete star_show_timer;
	if (myCarStatus){
	  car_move_timer->stop();
	  delete car_move_timer;
	  delete myCar;
	}
	if (myBombStatus){
	  bomb_move_timer->stop();
	  delete bomb_move_timer;
	  delete myBomb;
	}
	if (myMoonStatus){
	  moon_move_timer->stop();
	  delete moon_move_timer;
	  delete myMoon;
	}
	if (candy_is_here){
	  delete candy_timer;
	  delete myCandy;
	}
	if (candyStatus){
	  candyS->stop();
	  delete candyS;
	}
  stars.clear();
  view->setScene(scene);
}


  
