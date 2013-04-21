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
#include "bomb.h"
#include "thing.h"
#include "car.h"
#include "moon.h"
#include "girl.h"
#include "star.h"

using namespace std;

class MainWindow: public QWidget{
  Q_OBJECT
  
  public:
    explicit MainWindow();
    ~MainWindow();
    void show();
    
    string toStr(int);
    void add_life();
    void lose_life();
    bool isLive();
    void girlAction();
    void checkLife();
    void checkScore();
    
    friend class Bomb;
    friend class Car;
    
  private:
    int lifeNum;
    int scoreNum;
    int myBombTime; bool myBombStatus;
    int myMoonTime; bool myMoonStatus;
    int myGirlTime; bool myCarStatus;
    int myStarTime;
    bool checkCar;
    bool checkMoon;
    
    QGraphicsView *view;
    QGraphicsScene *scene;
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
    QString *name;
    QPushButton *Pause;
    
    QTimer *bomb_show_timer;
    QTimer *bomb_move_timer;
    Bomb *myBomb;
    
    QTimer *car_show_timer;
    QTimer *car_move_timer;
    Car *myCar;
    
    QTimer *moon_show_timer;
    QTimer *moon_move_timer;
    Moon *myMoon;
    
    QTimer *girl_timer;
    Girl *myGirl;
    
    vector<Star*> stars;
    QTimer *star_show_timer;
  
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
    void keyPressEvent(QKeyEvent *event);
};

#endif
