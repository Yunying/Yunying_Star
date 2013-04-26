#include <QtGui/QApplication>
#include "mainwindow.h"

using namespace std;

/** @mainpage  CSCI102 PA5: My Game: Star
  *
  * @author YUNYING TU
  *
  * @date 04-25-13
  *
  * @section Game Introduction
  *    The user will control a girl to collect Star, avoid EvilStar and Car, click on the Bomb to stop it from exploding
  *
  *	   Everytime the user reaches 1000 points, there will appear a Candy which will offer the girl 7-second protection
  *
  *	   Level up when the user reaches certain scores.
  *
  *    For more detailed Game description, please see my GameDesign File.
  *
  * @section Notes on how to read this Doxygen File
  *    Start Screen: The scene where the user enters the Username, get Instructions and click Start
  *
  *    Help Screen: The page that contains game instructions.
  *
  *    Game Scene: The scene where the user actually plays the game
  *
  *    Detailed description for each function is in the header files. Brief description could be found in .cpp files
  *
  */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
