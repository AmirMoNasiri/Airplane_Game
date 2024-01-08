#include"../include/myhelicopter.hpp"

using namespace std;

void MyHelicopter :: SetRow(int x)
{
    row = x;
}

void MyHelicopter :: SetColumn(int x)
{
    column = x;
}

void MyHelicopter ::PointPlus(int point)
{
    this->point += point;
}

size_t MyHelicopter :: GetPoint() const
{
    return point ;
}

int MyHelicopter :: GetColumn() const
{
    return column ;
}


int MyHelicopter :: GetRow() const
{
    return row ;
}