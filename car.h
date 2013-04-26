#ifndef MYCAR_H_
#define MYCAR_H_
#include <QGraphicsPixmapItem>

/** @class Car
  * Move horizontally \n
  * Will disappear after it goes too right to be in the screen. \n
  * It worth hundreds of points. The higher the level, the more points will be reduced when the girl hits the car. \n
  * The speed will go up as the level difficulty goes up \n
  */

using namespace std;

class Car : public QGraphicsPixmapItem{
  public:
    /** Default Constructor */
    Car();
    
    /** Destructor */
    ~Car();
    
    /** @param carImage the image of the car
      * @param int the random speed of the car
      * Once the girl hits the car, she will lose hundreds of points, the exact number depending on the level difficulty. \n
      */
    Car(QPixmap& carImage,int);
    
    /** Set the new position of the car. Y keeps the same but X will increase */
    void move();
    
    /** To check if the car is still in the screen */
    bool carStatus;
    
  private:
    /** initial x-coordinate */
    int x;
    
    /** initial y-coordinate */
    int v;
    
    /** width of the car */
    int width;
};



#endif

