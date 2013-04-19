#include "bomb.h"

using namespace std;

Bomb::Bomb(){}

Bomb::~Bomb(){}


Bomb::Bomb(QPixmap& bombIma, int nx, int ny, int nvx, int nvy) : 
  QGraphicsPixmapItem(bombIma){
    x = nx;
    y = ny;
    setPos(x, y);
    setZValue(2);
    vx = nvx;
    vy = nvy;
    width = 100;
    height = 100;
    
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
    //Everything is good. Update the QRectF that is actually displayed.
    //QPointF p( x, y );
    //QRectF r( rect() );
    //r.moveTo(p);
    //setRect( r );
}

