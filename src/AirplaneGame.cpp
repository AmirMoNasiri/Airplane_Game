#include "../include/gameInclude/AirplaneGame.h"
// #include "../include/gameInclude/menu.h"

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
   cout << ". ";
   sleep(1);
   cout << ". ";
   sleep(1);
   cout << ". ";
   sleep(1);
   cout.flush();

   system("cls");
   cout.flush();
   system(" pause");
}

