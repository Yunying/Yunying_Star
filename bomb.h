#ifndef BOMB_H_
#define BOMB_H_
#include <QGraphicsPixmapItem>

using namespace std;

/** @class Bomb
  * @brief A life will be lost if the bomb is not clicked 
  * The bomb will move randomly. \n
  * As the level difficulty goes up, the bomb will move faster
  */
class Bomb : public QGraphicsPixmapItem{
  public:
    /** Constructor. Set up the random position where the bomb will appear. \n
      * Initialize its speed.
      */
    Bomb();
    
    /** Destructor */
    ~Bomb();
    
    /** @param bomb The image of the bomb
      * @param nx The initial x-coordinate of the bomb
      * @param ny The initial y-coordinate of the bomb
      * @param nvs The velocity on x-axis of the bomb
      * @param nvy The velocity on y-axis of the bomb
      */
    Bomb(QPixmap& bomb,int nx, int ny, int nvx, int nvy);
    
    /** @param windowMaxX the width of the window 
      * @param windowMaxY the height of the window where the bomb can move
      * This functions set the new position of the bomb every interval time.
      */
    void move(int windowMaxX, int windowMaxY);
    
    /** Track if the bomb is clicked */
    bool bombClicked;
    
    /** If the bomb is clicked, it will change the bombClicked boolean value to true. \n
      * MainWindow class thus will make corresponding reaction to make the bomb disappear.
      */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
  
  private:
    /** initial x-coordinate */
    int x;
    
    /** initial y-coordinate */
    int y;
    
    /** initial x-velocity */
    int vx;
    
    /** initial y-velocity */
    int vy;
    
    /** width of the bomb */
    int width;
    
    /** height of the bomb */
    int height;
};

#endif


