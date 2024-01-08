#include"../include/barrier.hpp"

using namespace std;

void Barrier :: SetColumn(int column)
{
    this->column = column ;
}

void Barrier :: SetRow(int row)
{
    this->row = row ;
}

int Barrier :: GetColumn() const
{
    return column ;
}

int Barrier :: GetRow() const
{
    return row ;
}