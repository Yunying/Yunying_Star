#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <iostream>
#include <QObject>
#include <QMainWindow>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>
#include <QLineEdit>
#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>
#include <QPixmap>
#include <QBrush>
#include <QImage>
#include <QFont>
#include <QString>
#include <QKeyEvent>
#include <vector>
#include <string>
#include <sstream>
#include <QMenuBar>
#include <QAction>
#include "bomb.h"
#include "car.h"
#include "moon.h"
#include "girl.h"
#include "star.h"
#include "candy.h"
#include <QMenu>

using namespace std;

class MainWindow: public QMainWindow{
  Q_OBJECT
  
  public:
    explicit MainWindow();
    ~MainWindow();
    
    string toStr(int);
    void add_life();
    void lose_life();
    bool isLive();
    void girlAction();
    void checkLife();
    void checkScore();
    void checkStar(Star*);
    
    friend class Bomb;
    friend class Car;
    friend class GameScene;
    
  private:
    int lifeNum;
    int scoreNum;
    int myBombTime; bool myBombStatus;
    int myMoonTime; bool myMoonStatus;
    int myGirlTime; bool myCarStatus;
    int myStarTime;
    bool checkCar;
    bool checkMoon;
    int level;
    bool candyStatus;
    int bombShow;
    int moonShow;
    int carShow;
    
    QGraphicsView *view;
    QGraphicsScene *scene;
    QMenuBar *mb;
    QMenu *fileMenu;
    QGraphicsScene *gamescene;
    QMainWindow *window;
    QPushButton *start;
    QGraphicsSimpleTextItem *little_star;
    QGraphicsSimpleTextItem *twinkle;
    QGraphicsSimpleTextItem *usernametext;
    QLineEdit *username;
    QGraphicsSimpleTextItem *life;
    QGraphicsSimpleTextItem *score;
    QGraphicsSimpleTextItem *lifeN;
    QGraphicsSimpleTextItem *scoreN;
    QGraphicsSimpleTextItem *user;
    QGraphicsSimpleTextItem *userN;
    QGraphicsSimpleTextItem *levelT;
    QGraphicsSimpleTextItem *levelN;
    QString *name;
    QPushButton *Pause;
    QPushButton *quit;
    QPushButton *quit1;
    QPushButton *Instructions;
    QPushButton *back;
    QPixmap *Instruct;
    QGraphicsPixmapItem *InsImage;
    Candy *myCandy;
    
    QTimer *timers;
    
    QTimer *bomb_move_timer;
    Bomb *myBomb;
    
    QTimer *car_move_timer;
    Car *myCar;
    
    QTimer *moon_move_timer;
    Moon *myMoon;
    
    QTimer *girl_timer;
    Girl *myGirl;
    
    vector<Star*> stars;
    QTimer *star_show_timer;
    
    QTimer *candy_timer;
    bool candy_is_here;
    QTimer *candyS;
    int myCandyTime;
    
    QPixmap *greenStar;
    QPixmap *blueStar;
    QPixmap *redStar;
    QPixmap *evilStar;
    QPixmap *yellowStar;
    QPixmap *moonImage;
    QPixmap *carImage;
    QPixmap *bombImage;
    QPixmap *candyImage;
    QPixmap *candyGirlImage;
    QPixmap *girlImage;
    
  public slots:
    void handleStart();
    void handleBombShowTimer();
    void handleBombTimer();
    void handleCarShowTimer();
    void handleCarTimer();
    void handleMoonShowTimer();
    void handleMoonTimer();
    void handleGirlTimer();
    void handleStarTimer();
    void handlePause();
    void handleQuit();
    void handleIns();
    void handleBack();
    void handleCandy();
    void handleGirlCandy();
    void handleTimers();
    void keyPressEvent(QKeyEvent *event);
};

#endif
