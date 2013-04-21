#include "star.h"

using namespace std;

Star::Star(){}

Star::~Star(){}

Star::Star(QPixmap& starImage, int sx, int svy, int rancolor) : QGraphicsPixmapItem(starImage){
  setZValue(1);
  x = sx;
  y = 0;
  vy = svy;
  setPos(x, y);
  inscreen = true;
  color = rancolor;
}

void Star::move(){
  y += vy;
  if (y > 530){
    inscreen = false;
    return;
  }
  setPos(x, y);
}
