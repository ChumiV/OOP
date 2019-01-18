#ifndef CALC_H
#define CALC_H
#include <QStack>
#include <math.h>

struct MyType
{
    int type; //0-'+', 1-'-', 2-'*', 3-'|', 4-'^', 5-'e', 6-'ln', 7-'tn', 8-'sin', 9-'cos', -1 - number
    double value;
};

class Calc
{
public:
    QStack <MyType> box;
    bool calculation();
};

#endif // CALC_H
