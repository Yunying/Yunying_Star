#include "moon.h"
#include "girl.h"
#include "sun.h"
#include <iostream>

using namespace std;

Sun::Sun(){}

Sun::~Sun(){}

Sun::Sun(QPixmap& sun, int nx, Girl* girl) : Moon(sun, nx){
  x = nx;
  y = 760;
  vy = -1;
  setPos(x, y);
  setZValue(1);
  mygirl = girl;
  vx = 0;
}

void Sun::come(){
  y = y+vy;
  setPos(x, y);
}

void Sun::stay(){
  int distance = mygirl->x - x;

  vx = distance / 20;

  x = x+vx;

  setPos(x, y);
  vy = 0;
}

void Sun::leave(){
  vy+= 0.5;
  y += vy;
  setPos(x, y);
}
