#ifndef GIRL_H_
#define GIRL_H_
#include <QGraphicsPixmapItem>

using namespace std;
/** @class Girl
  * The user-controlled object. \n
  * Can move left, right and jump. \n
  * When it collides with other items in the screen, something will happen. \n
  * @brief The user-controlled object
  */
class Girl : public QGraphicsPixmapItem{
  
  public:
    /** Default Constructor */
    Girl();
    
    /** Destructor */
    ~Girl();
    
    /** @param Girl the Image of the girl */
    Girl(QPixmap& Girl);
    
    /** Control the girl to move to left */
    void moveLeft();
    
    /** Control the girl to move to right. */
    void moveRight();
    
    /** The first part of the girl's jump action. \n
      * The speed will decrease as the girl moves up.
      */
    void jumpU();
    
    /** The second part of the girl's jump action. \n
      * The speed will increase as the girl moves down.
      */
    void jumpD();
    friend class MainWindow;
    friend class Star;
    friend class Moon;
  private:
  
    /** initial x-coordinate */
    double x;
    
    /** initial y-coordinate */
    double y;
    
    /** initial y-velocity */
    double vy;
    
    /** initial x-velocity */
    double vx;
    
    /** width of the girl */
    int width;


    
};

#endif

