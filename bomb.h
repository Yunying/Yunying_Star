#ifndef BOMB_H_
#define BOMB_H_
#include <QGraphicsPixmapItem>

using namespace std;

class Bomb : public QGraphicsPixmapItem{
  public:
    Bomb();
    ~Bomb();
    Bomb(QPixmap& bomb,int, int, int, int);
    void move(int, int);
    bool bombClicked;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
  
  private:
    int x;
    int y;
    int vx;
    int vy;
    int width;
    int height;
};

#endif


