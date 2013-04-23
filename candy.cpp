#include "candy.h"
#include <iostream>

using namespace std;

Candy::Candy(){}

Candy::~Candy(){}

Candy::Candy(QPixmap& CandyImage, int sx) : QGraphicsPixmapItem(CandyImage){
  setZValue(5);
  x = sx;
  y = 550;
  
  setPos(x, y);
}
