#include "../include/gameInclude/AirplaneGame.h"

#include<iostream>
#include <cstdlib>
#include <unistd.h>


void AirplaneGame::run() // run function
{
   welcomeFirst();
   do
   {
      printMenu();
      setUserSelection();
   } while (exitFlag);
}

   // show welcome when run game
void AirplaneGame :: welcomeFirst()
{
   system("cls");
   cout << " WELCOME TO AIRPLANE GAME ";
   printDelayAnimation('.');
   system("cls");
   cout.flush();
   system(" pause");
}
void AirplaneGame :: printDelayAnimation(char c)
{
   for (size_t i = 0; i < 3; i++)
   {
      cout << c << " ";
      sleep(1);
   }
}

