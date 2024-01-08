#if !defined(MyHELICOPTER)
#define MyHELICOPTER

#include<iostream>

class MyHelicopter
{
    public :
    int row ;
    int column ;
    size_t point = 0;
    int heal = 3;

    void SetRow(int);
    void SetColumn(int);
    void PointPlus(int);
    size_t GetPoint()const;
    int GetColumn()const;
    int GetRow()const;
};



#endif // MyHELICOPTER
