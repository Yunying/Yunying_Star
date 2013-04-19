#ifndef BOMB_H_
#define BOMB_H_
#include <QGraphicsPixmapItem>

class MainWindow;

using namespace std;

class Bomb : public QGraphicsPixmapItem{
  public:
    Bomb();
    ~Bomb();
    Bomb(QPixmap& bomb,int, int, int, int, MainWindow*);
    void move(int, int);
    
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
  
  private:
    int x;
    int y;
    int vx;
    int vy;
    int width;
    int height;
    MainWindow *window;
};

#endif


