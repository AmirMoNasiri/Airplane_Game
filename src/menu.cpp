#include "../include/gameInclude/AirplaneGame.h"

#include<iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdexcept>

bool AirplaneGame :: correctSelection(int selection)
{
   switch (selection)
   {
   case NEWGAME:
   case LOADGAME:
   case SCORE:
   case HELP:
   case EXIT:
      return true;
      break;
   default:
      system("cls");
      throw invalid_argument(" WRONG INPUT ");
      return false;
      // throw exetion false selection charater
      break;
   }
   
}
void AirplaneGame :: setUserSelection()
{
   int selection ;
   cin >> selection;
   try
   {
      if (correctSelection(selection))
      {
         selectionMenuOption = selection;
         checkMenuInput();
      }
   }
   catch(const invalid_argument &e)
   {
      cerr << e.what();
      cout << "! ";
      sleep(1);
      cout << "! ";
      sleep(1);
      cout << "! ";
      sleep(1);
      cout.flush();
      printMenu();
      setUserSelection();
   }
}

int AirplaneGame :: getUserSelection() const
{
   return selectionMenuOption;
}

void AirplaneGame :: printMenu()
{
   system("cls");
   cout << " Airplane Game" << endl;
   cout << "------------------------" << endl;
   cout << " 1 - New Game " << endl;
   cout << " 2 - Load Game " << endl;
   cout << " 3 - Score " << endl;
   cout << " 4 - Help " << endl;
   cout << " 0 - Exit " << endl << endl;
   cout << " Enter : ";

}

void AirplaneGame :: checkMenuInput()
{
   switch (getUserSelection())
   {
   case NEWGAME:
      break;

   case LOADGAME:
      break;

   case SCORE:

      break;

   case HELP:
      helpMenu();
      system("pause");
      printMenu();
      setUserSelection();

      break;

   case EXIT:
      exitMenu();

      break;
   
   default:
      // throw exetion false selection charater
      break;
   }
}
void AirplaneGame :: exitMenu()
{
   system("cls");
   cout << " GoodBye ";
   cout << ". ";
   sleep(1);
   cout << ". ";
   sleep(1);
   cout << ". ";
   sleep(1);
   exitFlag = false;
}

void AirplaneGame :: helpMenu()
{
   system ("cls");
   cout << " HELP GAME"               << endl;
   cout << "------------------------" << endl;
   cout << " W - Going UP"            << endl;
   cout << " S - Going DOWN"          << endl;
   cout << " M - Shooting"            << endl;
   cout << " E - Exit Game to Menu"   << endl << endl;
}