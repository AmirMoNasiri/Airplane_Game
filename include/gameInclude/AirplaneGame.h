#ifndef AIRPLANEGAME_H
#define AIRPLANEGAME_H

#include <iostream>
#include <string>

using namespace std;


class AirplaneGame
{
private:
   enum MenuStatus {EXIT, NEWGAME , LOADGAME, SCORE, HELP};
   int  selectionMenuOption;  // selection Menu Option int
   bool exitFlag;
public:
   // AirplaneGame();
   // ~AirplaneGame();
   void run();
   // menu functions
   bool correctSelection();
   void setUserSelection();
   int getUserSelection() const;
   void printMenu();
   void checkMenuInput();

   // new game
   // load game
   // score
   // help
   // exit

};










#endif
