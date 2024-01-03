#ifndef USER_H
#define USER_H

#include "AirplaneGame.h"

using namespace std;

enum {NEWGAME = 1, LOADGAME, SCORE, HELP, EXIT};

class menu : public AirplaneGame
{
private:
   char selectionMO_CHAR; // selection Menu Option character
   int selectionMO_INT; // selection Menu Option int

public:
   menu();
   ~menu();
   bool correctSelection(char selection);
   void setUserSelection(char selection);
   int getUserSelection() const;
   void printMenu();
   

};






#endif