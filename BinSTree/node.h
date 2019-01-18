#ifndef NODE_H
#define NODE_H

#include <QWidget>
#include <QLabel>
#include <QObject>
#include <QtDebug>
#include <windows.h>


const QString unhlgt = "background-color: #aaaadd";
const QString hlgt = "background-color: #ff4444";
const int boarder = 2;
const int height = 24;
const int width = 44;
const int indent = 10;


class Node: public QObject
{
    Q_OBJECT
    void light();
    void dark();
public:
    QWidget *background;
    QLabel *value;

    Node();
    Node(QWidget *parent, const QString &data);
    Node(QWidget *parent);


    void setValue(const QString &data);


    void show();
    void move(int x,int y);
    int x();
    int y();
    int height();
    int width();    

signals:


public slots:
    void highlight();
};

#endif // NODE_H
