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
    
  private:
    int lifeNum;
    int scoreNum;
    int myBombTime;
    
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
  
  public slots:
    void handleStart();
    void handleBombShowTimer();
    void handleBombTimer();
};

#endif
