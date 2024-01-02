#include "../include/gameInclude/menu.h"



bool menu :: correctSelection(char selection)
{
   switch (selection)
   {
   case 'n':
   case 'N':
   case 'l':
   case 'L':
   case 's':
   case 'S':
   case 'e':
   case 'E':
      return true;
      break;
   
   default:
      return false;
      // throw exetion false selection charater
      break;
   }
   
}
void menu :: setUserSelection(char selection)
{
   char sel = ' ';
   if (correctSelection)
   {
      selectionMO_CHAR = selection;
   } else
   {
      // throw exeption
   }
   
}

int menu :: getUserSelection() const
{
   return selectionMO_INT;
}

void menu :: printMenu()
{
   system("cls");
   cout << " Airplane Game" << endl;
   cout << "------------------------" << endl;
   cout << " New Game ----> N" << endl;
   cout << " Load Game ---> L" << endl;
   cout << " Score -------> S" << endl;
   cout << " Help --------> H" << endl;
   cout << " Exit --------> E" << endl << endl;

   cout << " Enter : ";
}