#ifndef MYTABLE_H
#define MYTABLE_H

#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include "mysapper.h"


class MyTable : public QObject
{
    Q_OBJECT

    MySapper ms;

    QWidget *widget;
    QPushButton *newgame;
    QLabel *score_box;
    QVector <QVector <QPushButton *>> boxes;
    QPushButton *flagButton;
    QWidget *bckgrnd;

public:
    MyTable(QMainWindow *parent = nullptr);

signals:

public slots:
    void draw();
    void show();
    void hide();
};

#endif // MYTABLE_H
