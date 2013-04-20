#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <iostream>
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
#include <vector>
#include <string>
#include <sstream>
#include "bomb.h"
#include "thing.h"
#include "car.h"
#include "moon.h"

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
    
    friend class Bomb;
    friend class Car;
    
  private:
    int lifeNum;
    int scoreNum;
    int myBombTime;
    int myMoonTime;
    
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
    QGraphicsSimpleTextItem *lifecount;
    QString *name;
    
    QTimer *bomb_show_timer;
    QTimer *bomb_move_timer;
    Bomb *myBomb;
    
    QTimer *car_show_timer;
    QTimer *car_move_timer;
    Car *myCar;
    
    QTimer *moon_show_timer;
    QTimer *moon_move_timer;
    Moon *myMoon;
  
  public slots:
    void handleStart();
    void handleBombShowTimer();
    void handleBombTimer();
    void handleCarShowTimer();
    void handleCarTimer();
    void handleMoonShowTimer();
    void handleMoonTimer();
};

#endif
