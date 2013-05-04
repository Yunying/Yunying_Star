#include "star.h"
#include <iostream>

using namespace std;

Star::Star(){}

Star::~Star(){}

Star::Star(QPixmap& starImage, int sx, int svy, int rancolor, Girl* girl) : QGraphicsPixmapItem(starImage){
  setZValue(1);
  x = sx;
  y = 0;
  vy = svy; vx = rand() % 5+2;
  setPos(x, y);
  inscreen = true;
  color = rancolor;
  if (color == 4){
    x = rand()%500+250;
    vy = 1;
    mygirl = girl;
    distance = 530;
  }
}

void Star::move(){
  if (color != 4){
    y += vy;
  }
  else {
    y += vy; 
    distance = distance -1;
    vx= (mygirl->x - x) / distance;
    if (vx > 8){
      x+= vx;
    }
    
    else if (vx < 2){
      if (mygirl->x > x){
        x+= 2;
      }
      else {
        x-= 2;
      }
    }
    else {
      x+= vx;
    }
  }
  if (y > 530){
    inscreen = false;
    return;
  }
  setPos(x, y);
}
