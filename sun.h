#ifndef SUN_H_
#define SUN_H_
#include <QGraphicsPixmapItem>
#include "moon.h"
#include "girl.h"

using namespace std;

class Sun : public Moon {
  public :
    Sun();
    ~Sun();
    Sun(QPixmap& sun, int nx, Girl* girl);
    void come();
    void leave();
    void stay();
  private:
    Girl* mygirl;
    
    double vx;
    double vy;

};

#endif
