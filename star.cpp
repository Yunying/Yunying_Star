#include "star.h"

using namespace std;

Star::Star(){}

Star::~Star(){}

Star::Star(QPixmap& starImage, int sx, int svy) : QGraphicsPixmapItem(starImage){
  setZValue(1);
  x = sx;
  y = 0;
  vy = svy;
  setPos(x, y);
  inscreen = true;
}

void Star::move(){
  y += vy;
  if (y > 500){
    inscreen = false;
    return;
  }
  setPos(x, y);
}
