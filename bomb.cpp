#include "bomb.h"
#include "mainwindow.h"

using namespace std;

Bomb::Bomb(){}

Bomb::~Bomb(){}


Bomb::Bomb(QPixmap& bombIma, int nx, int ny, int nvx, int nvy, MainWindow *mw) : 
  QGraphicsPixmapItem(bombIma){
    x = nx;
    y = ny;
    setPos(x, y);
    setZValue(2);
    vx = nvx;
    vy = nvy;
    width = 100;
    height = 100;
    window = mw;
    
}

void Bomb::move(int windowMaxX, int windowMaxY){

  x += vx;
  y += vy;

  if ( x < 0 ) {
    vx = -vx;
    x +=vx;
  }

  if ( y < 0 ) {
    vy = -vy;
    y +=vy;
  }

  if ( (x+width) > windowMaxX ) {
     vx = -vx;
     x+=vx;
  }

  if ( (y+height) > windowMaxY ) {
     vy = -vy;
     y+=vy;
  }

  setPos(x, y);
}

void Bomb::mousePressEvent(QGraphicsSceneMouseEvent *event){
  event = event;
  window->myBombTime = 500;
  
}









