#include "include/gameInclude/AirplaneGame.h"



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
      return false;
      system("cls");
      cout << " WRONG INPUT !!!" << endl;
      system("PAUSE");
      // throw exetion false selection charater
      break;
   }
   
}
void AirplaneGame :: setUserSelection()
{
   int selection = 1;
   cout << " Enter : ";
   cin >> selection;
   if (correctSelection)
   {
      selectionMenuOption = selection;
      checkMenuInput();
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
      break;

   case EXIT:
      cout << " GoodBye " << endl;
      exitFlag = false;
      break;
   
   default:
      // throw exetion false selection charater
      break;
   }
}