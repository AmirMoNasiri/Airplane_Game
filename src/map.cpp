#include"../include/map.hpp"

using namespace std;

void Map :: BuildMyHelicopter() // create a user helicopter in map
{
    srand(time(NULL));
    myHelicopter.row = rand() % 10 ;
    myHelicopter.column = rand() % (10 / 2) ;

    matrix[myHelicopter.row][myHelicopter.column] = 'H' ; // H : my helicopter
}


void Map :: BuildEnemiesHelicopter() // create a enemy helicopter in map
{
    srand(time(nullptr));

    EnemyHelicopter temp ; // instance of enemy

    for (size_t i = 0; i < 4; i++)
    {
        int row ,column ;
        row = rand() % 10 ;
        column = 9;

        while (matrix[row][column] != 0)
        {
            row = rand() % 10 ;
        }
        
        matrix[row][column] = 'h' ; // h : enemy helicopter
        temp.column = column ;
        temp.row = row ;
        temp.hitPoint = row * 10 ;
        enemyHelicopter.push_back(temp);
    }
}


void Map :: PrintGame() const // print map
{
    for (size_t i = 0; i <= 10; i++)
    {
        for (size_t k = 0; k < 41; k++)
            cout << "-" ;
        cout << endl;

        for (size_t j = 0; j < 10 && i != 10; j++)
        {
            cout << (j == 0 ? "| " : " ");
            cout << (matrix[i][j] == 0 ? ' ' : matrix[i][j]) << " |";
        }
        cout << endl;
    }
}


int Map :: IsGameOver() // check if game over or not
{
    gameOver = (myHelicopter.heal <= 0 ? 1 : 0);
    return gameOver;
}


void Map :: MoveEnemiesHelicopter() // enemies only can move left
{
    vector < EnemyHelicopter > temp ;

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            if (j == 0 && matrix[i][j] == 'h') // if enemy reach to beginning of the map we detect and destroy enemy
            {
                matrix[i][j] = 0;
                myHelicopter.heal--;

                for (size_t k = 0; k < enemyHelicopter.size() ; k++) // find location of enemy and update location
                {
                    if (enemyHelicopter[k].row == i && enemyHelicopter[k].column == j)
                        continue;

                    temp.push_back(enemyHelicopter[k]);
                }

                enemyHelicopter.clear();
                enemyHelicopter = temp;
                
            }

            if (matrix[i][j] == 'h') // means that we detect enemy helicopter
            {
                if (matrix[i][j - 1] == 0) // means that we can move left
                {
                    matrix[i][j - 1] = 'h';
                    matrix[i][j] = 0;

                    for (size_t k = 0; k < enemyHelicopter.size() ; k++) // find location of enemy and update location
                    {
                        if (enemyHelicopter[k].row == i && enemyHelicopter[k].column == j)
                        {
                            enemyHelicopter[k].column--;
                            break;
                        }
                    }

                }

                else if (matrix[i][j - 1] == '+' || matrix[i][j - 1] == '#') // means that shot reached to enemy
                {
                    matrix[i][j - 1] = 0;
                    matrix[i][j] = 0;

                    for (size_t k = 0; k < enemyHelicopter.size() ; k++) // find location of enemy and update location
                    {
                        if (enemyHelicopter[k].row == i && enemyHelicopter[k].column == j)
                        {
                            myHelicopter.PointPlus(enemyHelicopter[k].GetPoint());
                            continue;
                        }

                        temp.push_back(enemyHelicopter[k]);
                    }

                    enemyHelicopter.clear();
                    enemyHelicopter = temp ;
                }

                else if (matrix[i][j - 1] == 'H')
                {
                    matrix[i][j] = 0;
                    myHelicopter.heal--;

                    for (size_t k = 0; k < enemyHelicopter.size() ; k++) // find location of enemy and update location
                    {
                        if (enemyHelicopter[k].row == i && enemyHelicopter[k].column == j)
                        {
                            myHelicopter.PointPlus(enemyHelicopter[k].GetPoint());
                            continue;
                        }

                        temp.push_back(enemyHelicopter[k]);
                    }

                    enemyHelicopter.clear();
                    enemyHelicopter = temp ;
                }
            } // end of second if
        } // end of inner loop
    } // end of outer loop
} // end of function


void Map :: MoveRight() // user helicopter can move right
{
    if (myHelicopter.column + 1 < 10)
    {
        if (matrix[myHelicopter.row][myHelicopter.column + 1] == 0 || matrix[myHelicopter.row][myHelicopter.column + 1] == '+')
        {
            matrix[myHelicopter.row][myHelicopter.column] = 0;
            myHelicopter.column++;
            matrix[myHelicopter.row][myHelicopter.column] = 'H';
        }
        
        else if (matrix[myHelicopter.row][myHelicopter.column + 1] == 'h')
        {
            matrix[myHelicopter.row][myHelicopter.column] = 0;
            myHelicopter.column++;
            matrix[myHelicopter.row][myHelicopter.column] = 'H';
            myHelicopter.heal--;

            vector <EnemyHelicopter > temp ;

            for (size_t i = 0; i < enemyHelicopter.size() ; i++)
            {
                if (enemyHelicopter[i].row == myHelicopter.row && enemyHelicopter[i].column == myHelicopter.column)
                    continue;
                
                temp.push_back(enemyHelicopter[i]);
            }
            
            enemyHelicopter.clear();
            enemyHelicopter = temp;
        }
    }
}

void Map :: MoveLeft() // user helicopter can move left
{
    if (myHelicopter.column - 1 >= 0)
    {
        if (matrix[myHelicopter.row][myHelicopter.column - 1] == 0)
        {
            matrix[myHelicopter.row][myHelicopter.column] = 0;
            myHelicopter.column--;
            matrix[myHelicopter.row][myHelicopter.column] = 'H';
        }
        
        else if (matrix[myHelicopter.row][myHelicopter.column - 1] == 'h')
        {
            matrix[myHelicopter.row][myHelicopter.column] = 0;
            myHelicopter.column--;
            matrix[myHelicopter.row][myHelicopter.column] = 'H';
            myHelicopter.heal--;

            vector <EnemyHelicopter > temp ;

            for (size_t i = 0; i < enemyHelicopter.size() ; i++)
            {
                if (enemyHelicopter[i].row == myHelicopter.row && enemyHelicopter[i].column == myHelicopter.column)
                    continue;
                
                temp.push_back(enemyHelicopter[i]);
            }
            
            enemyHelicopter.clear();
            enemyHelicopter = temp;
        }
    }
}


void Map :: MoveUp() // user helicopter can move up
{
    if (myHelicopter.row - 1 >= 0)
    {
        if (matrix[myHelicopter.row - 1][myHelicopter.column] == 0)
        {
            matrix[myHelicopter.row][myHelicopter.column] = 0;
            myHelicopter.row--;
            matrix[myHelicopter.row][myHelicopter.column] = 'H';
        }

        else if (matrix[myHelicopter.row - 1][myHelicopter.column] == 'h')
        {
            matrix[myHelicopter.row][myHelicopter.column] = 0;
            myHelicopter.row--;
            matrix[myHelicopter.row][myHelicopter.column] = 'H';
            myHelicopter.heal--;

            vector <EnemyHelicopter > temp ;

            for (size_t i = 0; i < enemyHelicopter.size() ; i++)
            {
                if (enemyHelicopter[i].row == myHelicopter.row && enemyHelicopter[i].column == myHelicopter.column)
                    continue;
                
                temp.push_back(enemyHelicopter[i]);
            }
            
            enemyHelicopter.clear();
            enemyHelicopter = temp;
        }
    }
}


void Map :: MoveDown() // user helicopter can move down
{
    if (myHelicopter.row + 1 < 10)
    {
        if (matrix[myHelicopter.row + 1][myHelicopter.column] == 0)
        {
            matrix[myHelicopter.row][myHelicopter.column] = 0;
            myHelicopter.row++;
            matrix[myHelicopter.row][myHelicopter.column] = 'H';
        }
        
        else if (matrix[myHelicopter.row + 1][myHelicopter.column] == 'h')
        {
            matrix[myHelicopter.row][myHelicopter.column] = 0;
            myHelicopter.row++;
            matrix[myHelicopter.row][myHelicopter.column] = 'H';
            myHelicopter.heal--;

            vector <EnemyHelicopter > temp ;

            for (size_t i = 0; i < enemyHelicopter.size() ; i++)
            {
                if (enemyHelicopter[i].row == myHelicopter.row && enemyHelicopter[i].column == myHelicopter.column)
                    continue;
                
                temp.push_back(enemyHelicopter[i]);
            }
            
            enemyHelicopter.clear();
            enemyHelicopter = temp;
        }
    }
}


void Map :: MoveMyHelicopter() // 4 direction management
{
    // cout << "w : up , s : down , a : left , d : right (q : quit)" << endl;
    cout << "Keys : 'a' -> move left , 's' -> move down , 'd' -> move right , 'w' -> move up" << endl;
    cout << "If You Enter 'E' , 'e' , 'q' ,'Q' -> mean exit or quit " << endl;
    cout << "Enter A Key : " << endl;
    char key;
    cin >> key; // receive char from user

    switch (key)
    {
        case 'w':
        case 'W':
        {
            MoveUp();
            break;
        }
    
        case 's':
        case 'S':
        {
            MoveDown();
            break;
        }

        case 'a':
        case 'A':
        {
            MoveLeft();
            break;
        }

        case 'd':
        case 'D':
        {
            MoveRight();
            break;
        }

        case 'q':
        case 'Q':
        case 'e':
        case 'E':
        {
            ofstream myFile("helicopter.txt");

            if (!myFile.is_open())
            {
                cerr << "Error: Unable to open file for writing." << endl;
                exit(EXIT_FAILURE);
            }

            myFile << myHelicopter.row << ' ' << myHelicopter.column << ' ';
            myFile << myHelicopter.heal << ' ' << myHelicopter.point << endl;

            myFile << enemyHelicopter.size() << endl;

            for (size_t i = 0; i < enemyHelicopter.size() ; i++)
            {
                myFile << enemyHelicopter[i].row << ' ' << enemyHelicopter[i].column << ' ';
                myFile  << enemyHelicopter[i].hitPoint << endl;
            }

            for (size_t i = 0; i < 10; i++)
            {
                for (size_t j = 0; j < 10 ; j++)
                {
                    myFile << matrix[i][j] << ' ';
                }
                myFile << endl;
            }
            
            myFile.close();
            exit(EXIT_SUCCESS);
        }

        default:
        {
            cerr << "You Entered Invalid Character !!!" << endl;
            break;
        }
    }
}


void Map :: Begin()
{
    if (loadFromFile == 0) // 0 : loading disable , 1 : loading enable
    {
        BuildMyHelicopter();
        BuildBarrier();
        BuildEnemiesHelicopter();
    }

    while (gameOver == 0) // 0 : continue , 1 : game over 
    {
        system("cls");
        cout << "Health: " << myHelicopter.heal << endl;
        cout << "Point : " << myHelicopter.point << endl;
        ShotHelicopter();
        PrintGame();
        MoveMyHelicopter();

        if (IsGameOver() == 1)
        {
            remove("helicopter.txt");
            cout << "Game Over" << endl;
            return ;
        }
        
        MoveEnemiesHelicopter();
        MoveHelicopterShot();
        PrintGame();

        if (IsEmpty() == true)
            BuildEnemiesHelicopter();
    }   
}



void Map :: ShotHelicopter()
{
    if (matrix[myHelicopter.row][myHelicopter.column + 1] == 0)
        matrix[myHelicopter.row][myHelicopter.column + 1] = '+';


    else if (matrix[myHelicopter.row][myHelicopter.column + 1] == 'h')
    {
        vector < EnemyHelicopter > temp ;

        for (size_t i = 0; i < enemyHelicopter.size() ; i++)
        {
            if (enemyHelicopter[i].row == myHelicopter.row && enemyHelicopter[i].column == myHelicopter.column + 1)
            {
                myHelicopter.PointPlus(enemyHelicopter[i].GetPoint());
                continue;
            }
            temp.push_back(enemyHelicopter[i]);
        }

        matrix[myHelicopter.row][myHelicopter.column + 1] = 0;
    }
}



void Map :: MoveHelicopterShot()
{
    for (size_t i = 0; i < 10; i++)
    {
        for (int j = 9 ; j >= 0 ; j--)
        {
            if (matrix[i][j] == '+')
            {
                if (j == 9)
                    matrix[i][j] = 0;
                

                else if (matrix[i][j + 1] == 0)
                {
                    matrix[i][j] = 0;
                    matrix[i][j + 1] = '+';
                }

                else if (matrix[i][j + 1] == 'h')
                {
                    vector <EnemyHelicopter > temp ;

                    PrintGame();

                    for (size_t k = 0; k < enemyHelicopter.size() ; k++)
                    {
                        if (enemyHelicopter[k].row == i && enemyHelicopter[k].column == j + 1)
                        {
                            continue; 
                        }

                        temp.push_back(enemyHelicopter[i]);   
                    }
                    
                    enemyHelicopter.clear();
                    enemyHelicopter = temp;
                    matrix[i][j + 1] = 0;
                    matrix[i][j] = 0;
                } // end of else

                else if (matrix[i][j + 1] == '#')
                {
                    matrix[i][j] = 0;
                }
                
            } // end of outer if 
        } // end of inner loop
    } // end of outer loop 
} // end of function 


bool Map :: IsEmpty()
{
    int counter = 0 ;

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            if (matrix[i][j] == 'h')
                counter++;
        }
    }
    
    if (counter == 0)
        return true; 

    return false; 
}



void Map :: BuildBarrier()
{
    srand(time(nullptr));

    for (size_t i = 0; i < 10; i++)
    {
        int first = rand() % 10 ;
        int second = rand() % 10 ;

        while (matrix[first][second] != 0)
        {
            first = rand() % 10;
            second = rand() % 10 ;
        }
        
        matrix[first][second] = '#';
    }
}