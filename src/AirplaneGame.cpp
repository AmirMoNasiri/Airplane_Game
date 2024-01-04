#include "../include/gameInclude/AirplaneGame.h"
#include "../include/gameInclude/menu.h"

#include<iostream>
#include <cstdlib>
#include <unistd.h>


void AirplaneGame::run() // run function
{
   system("cls");
   cout << " WELCOME TO AIRPLANE GAME ";

   cout << ". ";
   sleep(1);
   cout << ". ";
   sleep(1);
   cout << ". ";
   sleep(1);
   cout.flush();
   // system("pause");
   do
   {
      printMenu();
      setUserSelection();
   } while (exitFlag);
   
}
