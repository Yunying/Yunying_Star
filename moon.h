#ifndef MOON_H_
#define MOON_H_
#include <QGraphicsPixmapItem>

using namespace std;

/** @class Moon
  * A life will be added if the user eats the moon. \n
  * It moves down from the top of the screen, stay for a few seconds, and then goes to leave. \n
  * If the user already has three lives, the moon would add 700 points.
  * @brief The life-Saver!
  */

class Moon : public QGraphicsPixmapItem{
  public:
    /** Default Constructor */
    Moon();
    
    /** Default Destructor */
    ~Moon();
    
    /** @param moon The image of the moon
      * @param nx the random x-coordinate of the moon
      */
    Moon(QPixmap& moon, int nx);
    
    /** The first part of the moon's moving: coming down from the top of the screen */
    void come();
    
    /** The last part of the moon's moving: going up from the bottom of the screen */
    void leave();
    
  private:
    /** initial y-coordinate */
    int y;
    
    /** initial x-coordinate */
    int x;
    
    /** initial y-velocity */
    int vy;
};

#endif

