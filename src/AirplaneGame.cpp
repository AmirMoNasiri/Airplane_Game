#include "include/gameInclude/AirplaneGame.h"
#include "../include/gameInclude/menu.h"

#include <stdlib.h>


AirplaneGame::AirplaneGame() // default constructor
{
   selectionMenuOption  = 10;
   exitFlag = true;
}
AirplaneGame::AirplaneGame() // parameter constructor
{

}
void AirplaneGame::run() // run function
{
   cout << " WELCOME TO AIRPLANE GAME" << endl;
   do
   {
      printMenu();
      setUserSelection();
   } while (exitFlag);
   
}
