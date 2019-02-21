#ifndef MYSAPPER_H
#define MYSAPPER_H

#include <vector>
#include <QDebug>
#include <QDateTime>

using namespace std;

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


class MySapper
{
    vector <vector <box>> field;
    bool new_game;
    bool end_game;
    bool flags;
    unsigned int score;

public:
    void bomb_random(int i, int j);
    void bomb_around(int i, int j);
    void NewGame();
    void GameOver();
    void click(int i, int j);

    vector <vector <box>> Field();
    bool New_Game();
    bool End_Game();
    bool Flags();
    void SetFlags(bool b);
    unsigned int Score();


    MySapper();
};

#endif // MYSAPPER_H
