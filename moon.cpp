#include "moon.h"
#include "girl.h"
#include <iostream>

using namespace std;

Moon::Moon(){}

Moon::~Moon(){}

Moon::Moon(QPixmap& moon, int nx, Girl* girl) : QGraphicsPixmapItem(moon){
  x = nx;
  y = 0;
  vy = 2;
  setPos(x, y);
  setZValue(1);
  mygirl = girl;
  vx = 0;
  distance = mygirl->x - x;
  dist = 200;
}

void Moon::come(){
  y = y+vy;
  distance = mygirl->x - x;
  dist--;
  if (dist ==0 ){
    dist = 1;
  }
  
  if (mygirl->x > trackx){
    if (mygirl->x < x){
      vx = 12*(mygirl->x-trackx)/dist;
      cout << "Case 1: " << vx << endl;
    }
    else {
      vx = 0;
    }
  }
  
  else if (mygirl->x < trackx && dist != 0){
    if (mygirl->x > x){
      vx = -12*(trackx-mygirl->x)/dist;
      cout << "Case 2: " << vx << endl;
    }
    else {
      vx = 0;
    }
  }

  if (vx > 7){
    vx = 7;
  }
  
  else if (vx < -10){
    vx = -10;
  }
  
  x = x+vx;

  if (x > 1020){
    x = 5;
  }
  
  else if (x<0){
    x = 1015;
  }
  
  setPos(x, y);
  trackx = mygirl->x;
}

void Moon::leave(){
  y = y-vy;
  setPos(x, y);
}
