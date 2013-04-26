#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <iostream>
#include <QObject>
#include <QMainWindow>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>
#include <QLineEdit>
#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>
#include <QPixmap>
#include <QBrush>
#include <QImage>
#include <QFont>
#include <QString>
#include <QKeyEvent>
#include <vector>
#include <string>
#include <sstream>
#include <QMenuBar>
#include <QAction>
#include "bomb.h"
#include "car.h"
#include "moon.h"
#include "girl.h"
#include "star.h"
#include "candy.h"
#include <QMenu>
#include <QVBoxLayout>

using namespace std;

class MainWindow: public QMainWindow{
  Q_OBJECT
  
  public:
    /** Game Constructor. Set up all things in the Start Screen */
    explicit MainWindow();
    
    /** Game Destructor */
    ~MainWindow();
    
    /** A function for coding convenience. 
      * To convert an int to a string. 
      * @param int The integer that's going to be converted into a string.
      * @return a string that can be used in various Qt functions
      */
    string toStr(int);
    
    /** Add life when the user gets a Moon */
    void add_life();
    
    /** Lose life when the user has a score below 0 or a Bomb explodes */
    void lose_life();

    /** Start the girl_timer to control the girl's jumping action when the user hits Space */
    void girlAction();
    
    /** Everytime the girl has a change in life number, this function will be called. \n
      * If the girl has already had three lives but still want to add, she will get 
      * 700 extra points but no more life. \n
      * If the life number equals 0, game over. \n
      * Other time, simply use toStr() to convert the lifeNum to a string and show it on the game scene.
      */
    void checkLife();
    
    /** Everytime the girl has a change in score number, this function will be called. \n
      * If the girl reaches 1000 points, a candy will appear. \n
      * Increase the level Number if r. \n
      * Other time, simply use toStr() to convert the lifeNum to a string and show it on the game scene.
      */
    void checkScore();
    
    /** Check if the star collides with the girl. 
      * If collided, add/reduce the score based on which kind of star is collided
      */
    void checkStar(Star*);
    
    friend class Bomb;
    friend class Car;
    friend class GameScene;
    
  private:
    /**The girl's life Number */
    int lifeNum;
    
    /**The girl's score Number */
    int scoreNum;
    
    /**The Qt item that's used to show the lifeNum to the scene */
    QGraphicsSimpleTextItem *lifeN;
    
    /**The Qt item that's used to show the lifeNum to the scene */
    QGraphicsSimpleTextItem *scoreN;
    
    /**The Qt item to show the word "LIFE" */
    QGraphicsSimpleTextItem *life;
    
    /**The Qt item to show the word "SCORE" */
    QGraphicsSimpleTextItem *score;
    
    /**Track the time of the Bomb's appearance */
    int myBombTime; 
    
    /**Track if the bomb is in the screen */
    bool myBombStatus;
    
    /**Track the time of the Moon's appearance */
    int myMoonTime; 
    
    /** Track if the moon is in the screen */
    bool myMoonStatus;
    
    /**To monitor the jump action of the girl.*/
    int myGirlTime; 
    
    /** Track if the car is in the screen */
    bool myCarStatus;
    
    /** To monitor the interval by which the star is appearing */
    int myStarTime;
    
    /** To check if the car has already hit the girl. \n
      * Due to the moving characteristic of the two item, multiple collision is possible. \n
      * This variable is used to avoid multiple score deduction.
      */
    bool checkCar;
    
    /** The same as checkCar. /n used to avoid multiple life addition. */
    bool checkMoon;
    
    /** Track the level of difficulty the player is at */
    int level;
    
    /** The Qt item used to show the word "LEVEL" */
    QGraphicsSimpleTextItem *levelT;
    
    /** The Qt item used to show the level difficulty to the user. Will change over time. */
    QGraphicsSimpleTextItem *levelN;
    
    /** Track if the girl is in the invincible status. \n
      * If it equals true, no things can hurt her score or life */
    bool candyStatus;
    
    /** Everytime the int reaches a number, a bomb will appear. */
    int bombShow;
    
    /** Everytime the int reaches a number, a moon will appear. */
    int moonShow;
    
    /** Everytime the int reaches a number, a car will appear. */
    int carShow;
    
    /** The view of the game. Scenes in the view will change according to the user's action. */
    QGraphicsView *view;
    
    /** The Starting Screen where the user can input the username, get help and hit start. */
    QGraphicsScene *scene;
    
    /** The scene in which the user actually plays the game */
    QGraphicsScene *gamescene;
    
    /** The window that contains the view */
    QMainWindow *window;
    
    /** The game will start as soon as the user clicks the button. \n
      * An error message will show if the user has not entered the username. */
    QPushButton *start;
    
    /** The Start Screen decoration */
    QGraphicsSimpleTextItem *little_star;
    
    /** The Start Screen decoration */
    QGraphicsSimpleTextItem *twinkle;
    
    /** The Start Screen decoration */
    QGraphicsSimpleTextItem *usernametext;
    
    /** The box where the user enters their username */
    QLineEdit *username;

    /** The Qt item used to show the word "USER" */
    QGraphicsSimpleTextItem *user;
    
    /** The Qt item used to show the username */
    QGraphicsSimpleTextItem *userN;

    /** The container of the user input. Later it will be transferred into a Qt item. */
    QString *name;
    
    /** If the user clicks the button during the game, all timers will stop working and the game will pause */
    QPushButton *Pause;
    
    /** The quit button in the game scene. */
    QPushButton *quit;
    
    /** The quit button in the Start Screen */
    QPushButton *quit1;
    
    /** The button will bring the user back to the Start Screen. They can choose to restart the 
      * game by clicking on Start again */
    QPushButton *restart;
    
    /** By clicking this the user will enter the Instruction page which contains the instructions
      * for how to play the game. */
    QPushButton *Instructions;
    
    /** Back to the Start Screen from the Instruction page. */
    QPushButton *back;
    
    /** The Instruction page is a pre-made picture that tells the user how to play the game */
    QPixmap *Instruct;
    
    /** The Qt items used to display the insturction image */
    QGraphicsPixmapItem *InsImage;
    
    /** The candy object that will appear every time the user get exactly 1000 points */
    Candy *myCandy;

	/** The timer used to control the interval by which the moon, bomb and car appear */
    QTimer *timers;
    
    /** The timer used to control the bomb moving */
    QTimer *bomb_move_timer;
    
    /** The bomb object. It looks like a huge black star.
      * @see Bomb */
    Bomb *myBomb;
    
    /** The timer used to control the car moving */
    QTimer *car_move_timer;
    
    /** The car object. 
      * @see Car*/
    Car *myCar;
    
    /** The timer used to control the moon moving */
    QTimer *moon_move_timer;
    
    /** The moon object
      * @see Moon
      */
    Moon *myMoon;
    
    /** The timer used to control the girl moving */
    QTimer *girl_timer;
    
    /** The girl object. The object that the user actually controls.
      * @see Girl */
    Girl *myGirl;
    
    /** A vector that used to store all the starts in the game scene. */
    vector<Star*> stars;
    
    /** The timers used to control the star-showing frequency */
    QTimer *star_show_timer;
    
    /** The timer used to control the endurance of the candy in the gamescene */
    QTimer *candy_timer;
    
    /** Track if candy is in the game scene.
      * The candy will disappear if \n
      * 1. The user has not touched it in three seconds \n
      * 2. The user eats it \n
      */
    bool candy_is_here;
    
    /** Control the endurance of the CandyTime for the girl */
    QTimer *candyS;
    
    /** Track the endurance of the CandyTime */
    int myCandyTime;
    
    /** Various images for the items in the game */
    QPixmap *greenStar;
    QPixmap *blueStar;
    QPixmap *redStar;
    QPixmap *evilStar;
    QPixmap *yellowStar;
    QPixmap *moonImage;
    QPixmap *carImage;
    QPixmap *bombImage;
    QPixmap *candyImage;
    QPixmap *candyGirlImage;
    QPixmap *girlImage;
    
  public slots:
    /** Start the game. \n
      * Set up the scene, including the background and the buttons. \n
      * Monitor the timers. \n
      * Initialize all the values. \n
      */
    void handleStart();
    
    /** Determine the random value of the bomb's showing coordinates and its speed. */
    void handleBombShowTimer();
    
    /** Control bomb's moving action. \n
      * If it explodes after 4 seconds, deduct the user's life number
      * If it is clicked, then everything is OK. */
    void handleBombTimer();
    
    /** Determine the speed of the car. And add the car item into the game scene. */
    void handleCarShowTimer();
    
    /** Control the moving action of the car. /n
      * If the girl does not avoid the car, implement the score deduction. /n
      * Remove the item after it goes out of the screen.
      */
    void handleCarTimer();
    
    /** Determine the random x-coordinate where the moon is going to show. \n
      */
    void handleMoonShowTimer();
    
    /** Control the moving action of the moon. \n
      * It will go down, stay and then move up. */
    void handleMoonTimer();
    
    /** Implement the girl's jumping action. \n
      * jump up and fall down. */
    void handleGirlTimer();
    
    /** Determine the random position where the next star will appear. \n
      * Control the time interval by which the star will appear. (Different depending on the level) \n
      * Determine the random color of the star to appear.
      * Determine whether the next star is evilStar. (It is random but the frequency will differentiate based on the level) \n
      * Monitor the position of every star. 
      * If a star goes lower the the girl, then it will disappear. */
    void handleStarTimer();
    
    /** Stop or Start all timers. */
    void handlePause();
    
    /** Quit the game */
    void handleQuit();
    
    /** Go to the instruction page */
    void handleIns();
    
    /** Go back to the Start Screen from the instruction page */
    void handleBack();
    
    /** When the function is called: \n
      * If there's not candy on the screen, add a candy. \n
      * If the girl eats the candy, remove the candy from the screen. The girl enters CandyStatus \n
      * If the girl does not eat the candy in 3 seconds, the candy will naturally disappear */
    void handleCandy();
    
    /** Monitor how long the girl has entered candyStatus. \n
      * Ensure that no life or score deduction will be applied during candy status
      * The girl will change to another color during candyStatus */
    void handleGirlCandy();
    
    /** The overall timer that controls the appearance of car, moon and bomb. */
    void handleTimers();
    
    /** Called when the user hits the Restart button.
      * pause the game. Remove all items in the screen and set the scene back to Start Screen */
    void handleRestart();
    
    /** The user uses key to play the game. */
    void keyPressEvent(QKeyEvent *event);
};

#endif
