#if !defined(BARRIER)
#define BARRIER

#include<iostream>

class Barrier
{
    public :
    int row ;
    int column ;

    void SetColumn(int column);
    void SetRow(int row);
    int GetColumn() const;
    int GetRow() const;
};


#endif // BARRIER
