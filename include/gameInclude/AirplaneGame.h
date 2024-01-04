#ifndef AIRPLANEGAME_H
#define AIRPLANEGAME_H

#include <iostream>
#include <string>

using namespace std;


class AirplaneGame
{
private:
   // enum type for selection of user in menu
   enum MenuStatus {EXIT, NEWGAME , LOADGAME, SCORE, HELP};

   // selection Menu Option int
   int  selectionMenuOption;

   // when user selection Exit exitFlag = ture
   bool exitFlag;


public:
   // AirplaneGame();
   // ~AirplaneGame();
   void run();
   void welcomeFirst();


   // menu functions
   bool correctSelection();
   int  getUserSelection() const;
   void setUserSelection();
   void printMenu();
   void checkMenuInput();
   // new game
   // load game
   // score
   // help
   void helpMenu();
   void exitMenu();


};










#endif
