#ifndef Candy_H_
#define Candy_H_
#include <QGraphicsPixmapItem>

using namespace std;

class Candy : public QGraphicsPixmapItem{
  public:
    Candy();
    ~Candy();
    Candy(QPixmap& myCandy, int);
    
  protected:
    int x;
    int y;
    
};

#endif

