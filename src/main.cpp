/*
    Helicopter Game - Advanced Programming

        Bu-Ali Sina University 
        Semester 4021 - 1402-1403

        AmirMohammad Nasiri - 40012358043
*/


#include"../include/map.hpp"

using namespace std;

int main()
{
    Map map ;
    ifstream myFile("helicopter.txt");

    if (myFile.is_open())
    {
        int tempNumber ;

        for (size_t i = 0; i < 4; i++)
        {
            myFile >> tempNumber;

                if(i == 0)
                    map.myHelicopter.row = tempNumber;
            
                else if(i == 1)
                    map.myHelicopter.column = tempNumber;

                else if(i == 2)
                    map.myHelicopter.heal = tempNumber;

                else
                    map.myHelicopter.point = tempNumber;
            }

        int size ;
        myFile >> size ;
        // cout << size << endl;

        for (size_t i = 0; i < size ; i++)
        {
            int number1 ;
            int number2 ;
            int hit;

            myFile >> number1 >> number2 >> hit;
            EnemyHelicopter temp ;
            temp.row = number1 ;
            temp.column = number2;
            temp.hitPoint = hit;
            map.enemyHelicopter.push_back(temp);
        }
        
        char tempChar;

        for (size_t i = 0; i < 10; i++)
        {
            for (size_t j = 0; j < 10 ; j++)
            {
                myFile >> tempChar;
                map.matrix[i][j] = tempChar;
            }
        }

        map.loadFromFile = true;
        myFile.close();

    }

    map.Begin();

    return 0;
}
