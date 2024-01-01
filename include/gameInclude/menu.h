#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class menu
{
private:
   string userSelectOption;
public:
   menu();
   ~menu();
   void printMenu();
   int checkStringOption();
   string getUserSelectionOption() const;
   void setUserSelectionOption();
};

menu::menu()
{

}

menu::~menu()
{
}







#endif