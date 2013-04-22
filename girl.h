#ifndef GIRL_H_
#define GIRL_H_
#include <QGraphicsPixmapItem>
#include <QKeyEvent>


using namespace std;

class Girl : public QGraphicsPixmapItem{
  
  public:
    Girl();
    ~Girl();
    Girl(QPixmap& Girl);
    void moveLeft();
    void moveRight();
    void jumpU();
    void jumpD();
    friend class MainWindow;
  private:
    double x;
    double y;
    double vy;
    double vx;
    int width;


    
};

#endif

