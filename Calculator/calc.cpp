#include "calc.h"
#include <math.h>

bool Calc::calculation()
{
    double x;
    MyType temp;

    if (box.size() == 2)
    {
        temp = box.pop();

        switch(temp.type)
        {
            case 9:
                temp.value = cos(box.pop().value);
            break;

            case 8:
                temp.value = sin(box.pop().value);
            break;

            case 7:
                 temp.value = tan(box.pop().value);
            break;

            case 6:
                x = box.pop().value;
                if (x <= 0)
                    return true;
                else
                    temp.value = log(x);
            break;

            case 5:
                temp.value = exp(box.pop().value);
            break;
        }

        temp.type = -1;
        box.push(temp);
    }
    else if (box.size() == 3)
    {
        x = box.pop().value;

        temp = box.pop();

        switch(temp.type)
        {
            case 4:
                temp.value = pow(box.pop().value, x);
            break;

            case 3:
                if (x == 0)
                  return true;
                else
                    temp.value = box.pop().value / x;
            break;

            case 2:
                temp.value = box.pop().value * x;
            break;

            case 1:
                temp.value = box.pop().value - x;
            break;

            case 0:
                temp.value = box.pop().value + x;
            break;
        }

        temp.type = -1;
        box.push(temp);
    }
    else if (box.size() == 1)
    {
        temp = box.pop();
        if (temp.type == -1)
            box.push(temp);
    }

    return false;
}
