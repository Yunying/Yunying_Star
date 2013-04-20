#ifndef MOON_H_
#define MOON_H_
#include <QGraphicsPixmapItem>


using namespace std;

class Moon : public QGraphicsPixmapItem{
  public:
    Moon();
    ~Moon();
    Moon(QPixmap& moon, int nx);
    void come();
    void leave();
    
  private:
    int y;
    int x;
    int vy;
};

#endif

