#if !defined(ENEMYHELICOPTER)
#define ENEMYHELICOPTER

#include<iostream>

class EnemyHelicopter
{
    public :
    size_t hitPoint = 0; // each enemy has own hit point
    int row ;
    int column ;

    void SetPoint(int); // set the hit point
    void SetRow(int); // set the location
    void SetColumn(int); // set the
    size_t GetPoint() const; // get the hit point
    int GetRow() const; // get the row
    int GetColumn() const; // get the column
};



#endif // ENEMYHELICOPTER
