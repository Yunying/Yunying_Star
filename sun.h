#ifndef SUN_H_
#define SUN_H_
#include <QGraphicsPixmapItem>
#include "moon.h"
#include "girl.h"

using namespace std;
/** @class Sun 
  * This is an AI item. \n
  * It has three phases of moving: come, leave and stay.
  * When it is staying, it will track the girl's position. This will last for several seconds.
  * When it finishes its tracking status, it will swiftly drop and hits the girl.
  * If the girl is hit, she will get 50 points deduction.
  * @brief AI item
  */
class Sun : public Moon {
  public :
    /** Default Constructor */
    Sun();
    
    /** Default Destructor */
    ~Sun();
    
    /** @param sun The image of the sun
      * @param nx the random initial x-coordinate
      * @param girl used to track the girl's position
      */
    Sun(QPixmap& sun, int nx, Girl* girl);
    
    /** Rise from the bottom of the screen with a slow speed */
    void come();
    
    /** Quickly drop from the top of the screen to try to hit the girl */
    void leave();
    
    /** Hang up in the sky with constanct y-coodinate. But the x-coordinate changes as the girl moves */
    void stay();
  private:
  
    /** Used to track the girl's position */
    Girl* mygirl;
    
    /** The x-velocity. Will be used in the stay phase */
    double vx;
    
    /** The y-velocity. It will increase as the sun drops from the sky */
    double vy;

};

#endif
