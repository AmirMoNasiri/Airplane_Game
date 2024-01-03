#ifndef AIRPLANEGAME_H
#define AIRPLANEGAME_H

#include <iostream>
#include <string>

using namespace std;

enum MenuStatus {EXIT, NEWGAME , LOADGAME, SCORE, HELP};

class AirplaneGame
{
private:
   int  selectionMenuOption;  // selection Menu Option int
   bool exitFlag;
public:
   AirplaneGame();
   ~AirplaneGame();
   void run();
   // menu functions
   bool correctSelection(int selection);
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
