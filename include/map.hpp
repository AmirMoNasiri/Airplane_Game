#if !defined(MAP)
#define MAP

#include"myhelicopter.hpp"
#include"enemyhelicopter.hpp"
#include"barrier_inher.hpp"

#include<ctime>
#include<vector>
#include<fstream>


// int time_start = time(nullptr);

class Map
{
    public :
    char matrix[10][10]{0}; // array of char for use in map
    MyHelicopter myHelicopter; // user helicopter information
    std::vector<EnemyHelicopter> enemyHelicopter; // enemies helicopter information

    int gameOver = 0; // game over : 0 : continue ---- 1 : game over
    int loadFromFile = 0; // load from file  0 : not loaded ---- 1 : loaded form file

    void BuildMyHelicopter(); // create a user helicopter
    void BuildEnemiesHelicopter(); // create a enemy
    void PrintGame() const; // print the map
    void Begin(); // run the game
    int IsGameOver() ; // check game over
    void MoveMyHelicopter(); // user can move up ,down ,left ,right
    void MoveEnemiesHelicopter(); // enemy just can move to left
    void BuildBarrier() ;

    void MoveRight(); // move user right
    void MoveLeft(); // move user left
    void MoveUp(); // move user up
    void MoveDown(); // move user down

    void ShotHelicopter(); // if user move , helicopter shot to right
    void MoveHelicopterShot() ; // each shot character in the map will be moved to right
    bool IsEmpty() ; // if all of enemies are died we detect 
};


#endif // MAP
