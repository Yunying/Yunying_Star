#include "smartstar.h"

SmartStar::SmartStar(){}
SmartStar::~SmartStar(){}

SmartStar::SmartStar(QPixmap& starImage, int sx, int svy, int rancolor, Girl* girl, int mylevel) :
  Star(starImage, sx, svy, rancolor){
    mygirl = girl;
    distance = 531;
    vy = mylevel;
  }
  
void SmartStar:: move(){
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
    
  if (y > 530){
    inscreen = false;
    return;
  }
  
  setPos(x, y);
}
