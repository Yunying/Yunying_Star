#include "girl.h"
#include <iostream>

using namespace std;

Girl::Girl(){}

Girl::~Girl(){}

Girl::Girl(QPixmap& girlImage) : QGraphicsPixmapItem(girlImage){
  setPos(500, 500);
  setZValue(2);
  x = 500;
  y = 500;
  vy = 10;
  vx = 15;
  width = 80;
}

void Girl::moveLeft(){
  x = x-vx;
  setPos(x, y);
}

void Girl::moveRight(){
  x = x+vx;
  setPos(x, y);
}

void Girl::jumpU(){
    vy = vy - 0.4;
    y = y-vy;
    setPos(x, y);
}

void Girl::jumpD(){
    vy = vy+0.4;
    if (y+vy > 500) {setPos(x, 500);}
    else {
      y = y+vy;
      setPos(x, y);
    }
}

  
