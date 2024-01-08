#include"../include/enemyhelicopter.hpp"

using namespace std;

void EnemyHelicopter :: SetPoint(int point)
{
    hitPoint = point;
}


size_t EnemyHelicopter :: GetPoint() const
{
    return hitPoint;
}


void EnemyHelicopter :: SetRow(int x)
{
    row = x;
}


void EnemyHelicopter :: SetColumn(int x)
{
    column = x;
}


int EnemyHelicopter :: GetColumn() const
{
    return column;
}


int EnemyHelicopter :: GetRow() const
{
    return row;
}