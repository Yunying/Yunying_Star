#include "star.h"
#include <iostream>

using namespace std;

Star::Star(){}

Star::~Star(){}

Star::Star(QPixmap& starImage, int sx, int svy, int rancolor) : QGraphicsPixmapItem(starImage){
  setZValue(1);
  x = sx;
  y = 0;
  vy = svy; vx = rand() % 5+2;
  setPos(x, y);
  inscreen = true;
  color = rancolor;
  if (color == 4){
    x = rand()%500+250;
    vy = 2;
  }
}

void Star::move(){
  if (color != 4){
    y += vy;
  }
  else {
    y += vy+1; 
    if (x<200 || x>800){
      vx = -vx;
    }
    x += vx;
  }
  if (y > 530){
    inscreen = false;
    return;
  }
  setPos(x, y);
}
