#ifndef SMARTSTAR_H_
#define SMARTSTAR_H_
#include <QGraphicsPixmapItem>
#include "star.h"
#include "girl.h"

using namespace std;
/** @class SmartStar
  * Inherited from Star
  * 50 points will be deducted if the girl hits the star
  * The SmartStar will track the girl's position to adjust its falling route
  * @brief An AI item
  */
 
class SmartStar : public Star{
  public:
    /** Default Constructor */
    SmartStar();
    
    /** Default Destructor */
    ~SmartStar();
    
    /** @param starImage The image of the star
      * @param sx the random initial x-coordinate
      * @param svy the random initial y-velocity
      * @param rancolor the smartstar will have a color value of 5
      * @param girl used to track the girl's position
      * @param mylevel the SmartStar will have different velocity at different levels
      */
    SmartStar(QPixmap& starImage, int sx, int svy, int rancolor, Girl* girl, int mylevel);
    
    /** Move function. \n
      * The SmartStar will track the girl's position when it's moving
      */
    void move();
  protected:
  
    /** The difference in the y-coordinate between the girl and the star */
    int distance;
    
    /** Used to track the girl's position */
    Girl *mygirl;
};
 
#endif
 
 
 
 
 
 
 
 
 

