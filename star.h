#ifndef STAR_H_
#define STAR_H_
#include <QGraphicsPixmapItem>

using namespace std;

/** @class Star
  * Star is the most frequently appearing items in the game. \n
  * They drop verdictly from the top of the screen. \n
  * There are two kinds of stars: normal star and EvilStar. \n
  * Evil Star worths -20 points while normal star worths 20 points.
  * Score will change when the girl collides with the star.
  * @brief Collect the shiny ones, Avoid the evil ones and Enjoy!
  */
class Star : public QGraphicsPixmapItem{
  public:
    /** Default Constructor */
    Star();
    
    /** Destructor */
    ~Star();
    
    /** @param myStar the image of the star \n
      * @param sx the random x-coordinate where the star will appear. \n
      * @param svy the random speed of the star \n
      * @param rancolor the random color of the star, 4 means an evilstar. \n
      */
    Star(QPixmap& myStar, int sx, int svy, int rancolor);
    
    /** Move the star. A normal star will drop verdictly. \n
      * An Evil star will move in a Z-Shape.
      */
    virtual void move();
    
    /** Track if the star is still in the screen */
    bool inscreen;
    
    /** The color of the star. 0-3 is the same normal star while 4 means an evil star */
    int color;
    
  protected:
    /** initial x-coordinate */
    double x;
    
    /** initial y-coordinate */
    int y;
    
    /** initial y-velocity */
    int vy;
    
    /** initial x-velocity */
    double vx;
    
    
};

#endif


