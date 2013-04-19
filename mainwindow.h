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
#include <QPixmap>
#include <QBrush>
#include <QImage>
#include <QFont>
#include <vector>

using namespace std;

class MainWindow: public QWidget{
  Q_OBJECT
  
  public:
    explicit MainWindow();
    ~MainWindow();
    void show();
    
    void add_life();
    void lose_life();
    bool isLive();
    
  private:
    int lifeNum;
    int score;
    
    QGraphicsView *view;
    QGraphicsScene *scene;
    QGraphicsScene *gamescene;
    QMainWindow *window;
    QPushButton *start;
    QGraphicsSimpleTextItem *little_star;
    QGraphicsSimpleTextItem *twinkle;
    QGraphicsSimpleTextItem *usernametext;
    QLineEdit *username;
    QPixmap *lifemoon;
    QGraphicsPixmapItem *lifeMoon;
    
  
  public slots:
    void handleStart();
};

#endif
