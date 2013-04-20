#include "car.h"

using namespace std;

Car::Car(){}

Car::~Car(){}

Car::Car(QPixmap& carImage,int nv):
  QGraphicsPixmapItem(carImage){
    x = 0;
    v = nv;
    setZValue(3);
    setPos(x, 510);
    width = 100;
    carStatus = false;
}

void Car::move(){
  x = x+v;
  
  if ((x+width) > 1020){
    carStatus = true;
    return;
  }
  
  setPos(x, 510);
}

