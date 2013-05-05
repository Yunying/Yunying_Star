#ifndef SMARTSTAR_H_
#define SMARTSTAR_H_
#include <QGraphicsPixmapItem>
#include "star.h"
#include "girl.h"

using namespace std;
 
class SmartStar : public Star{
  public:
    SmartStar();
    ~SmartStar();
    SmartStar(QPixmap& starImage, int sx, int svy, int rancolor, Girl* girl, int mylevel);
    void move();
  protected:
    int distance;
    Girl *mygirl;
};
 
#endif
 
 
 
 
 
 
 
 
 

