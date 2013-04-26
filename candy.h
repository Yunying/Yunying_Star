#ifndef Candy_H_
#define Candy_H_
#include <QGraphicsPixmapItem>

using namespace std;
/** @class This class represents the candy that will appear everytime the user gets 1000 points. \n
  * It will stay on the screen for two seconds if the user does not eat it. \n
  * If the user eats it, the user can get 7-second candyTime. \n
  * During the candyTime, nothing can hurt the user.
  */
class Candy : public QGraphicsPixmapItem{
  public:
    /** Default Constructor */
    Candy();
    
    /** Default Destructor */
    ~Candy();
    
    /** @param myCandy The image of the candy
      * @param int the random x-coordinate of the candy
      */
    Candy(QPixmap& myCandy, int);
    
  protected:
    /** initial x-coordinate */
    int x;
    /** initial y-coordinate */
    int y;
    
};

#endif

