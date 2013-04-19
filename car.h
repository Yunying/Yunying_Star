#ifndef MYCAR_H_
#define MYCAR_H_
#include <QGraphicsPixmapItem>

//class MainWindow;

using namespace std;

class Car : public QGraphicsPixmapItem{
  public:
    Car();
    ~Car();
    Car(QPixmap& carImage,int);
    void move();
    
    bool carStatus;
    
  private:
    int x;
    int v;
    int width;
};



#endif

