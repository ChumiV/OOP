#ifndef MYTABLE_H
#define MYTABLE_H

#include <QObject>
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include <QDebug>
#include <QDateTime>

enum mytype {open, close, flag};

struct box
{
    mytype type;
    int value;
    bool bomb;
};

const int width = 17;
const int height = 11;
const int bomb_amount = 20;

class MyTable : public QObject
{
    Q_OBJECT

    QVector <QVector <box>> field;
    bool new_game;
    bool end_game;
    bool flags;
    unsigned int score;

    QPushButton *newgame;
    QLabel *score_box;
    QVector <QVector <QPushButton *>> boxes;
    QPushButton *flagButton;
    QWidget *bckgrnd;

    void bomb_random(int i, int j);
    void bomb_around(int i, int j);
    void NewGame();
    void GameOver();

public:
    MyTable(QMainWindow *parent = nullptr);

signals:

public slots:
    void draw();
    void click(int i, int j);
};

#endif // MYTABLE_H
