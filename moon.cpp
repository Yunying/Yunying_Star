#include "moon.h"

using namespace std;

Moon::Moon(){}

Moon::~Moon(){}

Moon::Moon(QPixmap& moon, int nx) : QGraphicsPixmapItem(moon){
  x = nx;
  y = 0;
  vy = 2;
  setPos(x, y);
  setZValue(1);
}

void Moon::come(){
  y = y+vy;
  setPos(x, y);
}

void Moon::leave(){
  y = y-vy;
  setPos(x, y);
}
