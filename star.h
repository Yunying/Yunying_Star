#ifndef STAR_H_
#define STAR_H_
#include <QGraphicsPixmapItem>

using namespace std;

class Star : public QGraphicsPixmapItem{
  public:
    Star();
    ~Star();
    Star(QPixmap& myStar, int, int, int);
    void move();
    bool inscreen;
    int color;
    
  private:
    int x;
    int y;
    int vy;
    int vx;
    
    
};

#endif

