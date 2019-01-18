#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QErrorMessage>
#include <iostream>
#include <QString>

using namespace std;

class Exception
{
    int num;
    QString str;
public:
    Exception(int num, QString str);

    void showErrorMsg();
};
#endif // EXCEPTION_H
