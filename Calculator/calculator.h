#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QVector>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "calc.h"
#include "mainwindow.h"

class calculator: public QObject
{
    Q_OBJECT
private:
    void location();

public:
    calculator(QMainWindow *new_window);
    Calc c;
    MyType temp;
    QVector <QPushButton *> buttons;
    QMainWindow *w;
    QLabel *l;
    int dotIsClicked;
    QList <QLabel*> history;

    void change(int num);
    void changeSign();
    void del();
    void solut();
    void goStack();
    void refreshHistory();

signals:
    void valueIsChange();

    void updHistory();
    void newSolution();

public slots:
    void outputValue();
    void addHistory();
    void updateHistory();
};

#endif // CALCULATOR_H
