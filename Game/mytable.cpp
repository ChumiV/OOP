#include "mytable.h"


void MyTable::draw()
{
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
        {
            if (field[i][j].type == open)
            {
                if (field[i][j].bomb == false)
                {
                    if (field[i][j].value > 0)
                    {
                        boxes[i][j]->setStyleSheet("background: #fdd700; color: #202020;");
                        boxes[i][j]->setFont(QFont("Helvetica", 16));
                        boxes[i][j]->setText(QString::number(field[i][j].value));
                    }
                    else
                    {
                        boxes[i][j]->setStyleSheet("background: #fdd700;");
                        boxes[i][j]->setText("");
                    }
                }
                else
                {
                    boxes[i][j]->setStyleSheet("background: #dc143c;");
                }
            }
            if (field[i][j].type == close)
            {
                boxes[i][j]->setStyleSheet("");
                boxes[i][j]->setText("");
            }
            if (field[i][j].type == flag)
            {
                boxes[i][j]->setStyleSheet("background: #6495ed");
                boxes[i][j]->setText("");
            }
        }

    score_box->setText(QString::number(score));
}

void MyTable::GameOver()
{
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
        {
            field[i][j].type = open;
        }

    end_game = true;
}

void MyTable::bomb_random(int i, int j)
{
    int bomb_num = 0;
    int a, b;

    qsrand(QDateTime::currentMSecsSinceEpoch());

    while (bomb_num < bomb_amount)
    {
        a = qrand()%width;
        b = qrand()%height;

        if (a != i || b != j)
        {
            if (field[i][j].bomb == false)
            {
                bomb_num++;
                field[a][b].bomb = true;
            }
        }
    }
}

void MyTable::bomb_around(int i, int j)
{
    if (i > 0 && i < width-1)
    {
        if (j > 0 && j < height-1)
        {
            field[i-1][j].value++;
            field[i-1][j-1].value++;
            field[i-1][j+1].value++;
            field[i][j-1].value++;
            field[i][j+1].value++;
            field[i+1][j].value++;
            field[i+1][j-1].value++;
            field[i+1][j+1].value++;
        }
        if (j == 0)
        {
            field[i-1][j].value++;
            field[i-1][j+1].value++;
            field[i][j+1].value++;
            field[i+1][j+1].value++;
            field[i+1][j].value++;
        }
        if (j == height-1)
        {
            field[i-1][j].value++;
            field[i-1][j-1].value++;
            field[i][j-1].value++;
            field[i+1][j-1].value++;
            field[i+1][j].value++;
        }
    }
    if (i == 0)
    {
        if (j > 0 && j < height-1)
        {
            field[i][j-1].value++;
            field[i][j+1].value++;
            field[i+1][j-1].value++;
            field[i+1][j].value++;
            field[i+1][j+1].value++;
        }
        if (j == 0)
        {
            field[i][j+1].value++;
            field[i+1][j+1].value++;
            field[i+1][j].value++;
        }
        if (j == height-1)
        {
            field[i][j-1].value++;
            field[i+1][j-1].value++;
            field[i+1][j].value++;
        }
    }
    if (i == width-1)
    {
        if (j > 0 && j < height-1)
        {
            field[i][j-1].value++;
            field[i][j+1].value++;
            field[i-1][j].value++;
            field[i-1][j-1].value++;
            field[i-1][j+1].value++;
        }
        if (j == 0)
        {
            field[i][j+1].value++;
            field[i-1][j+1].value++;
            field[i-1][j].value++;
        }
        if (j == height-1)
        {
            field[i][j-1].value++;
            field[i-1][j-1].value++;
            field[i-1][j].value++;
        }
    }
}

void MyTable::NewGame()
{
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
        {
            field[i][j].type = close;
            field[i][j].value = 0;
            field[i][j].bomb = false;
        }

    new_game = true;
    end_game = false;
    flags = false;
    score = 0;

    draw();
}

void MyTable::click(int i, int j)
{
    if (field[i][j].type != open && end_game == false)
    {
        if (flags == true)
        {
            if (field[i][j].type == flag)
                field[i][j].type = close;
            else
                field[i][j].type = flag;
        }
        else
        {
            if (new_game == true)
            {
                bomb_random(i, j);

                for (int a = 0; a < width; a++)
                    for (int b = 0; b < height; b++)
                    {
                        if (field[a][b].bomb == true)
                        {
                            bomb_around(a, b);
                        }
                    }

                new_game = false;

                click(i, j);
            }
            else
            {
                if (field[i][j].bomb == true)
                    GameOver();
                else
                {
                    field[i][j].type = open;
                    score++;

                    if (score == width*height - bomb_amount)
                    {
                        GameOver();
                    }

                    if (field[i][j].value == 0)
                    {
                        if (i > 0 && i < width-1)
                        {
                            if (j > 0 && j < height-1)
                            {
                                click(i-1, j);
                                click(i-1, j-1);
                                click(i-1, j+1);
                                click(i, j-1);
                                click(i, j+1);
                                click(i+1, j);
                                click(i+1, j-1);
                                click(i+1, j+1);
                            }
                            if (j == 0)
                            {
                                click(i-1, j);
                                click(i-1, j+1);
                                click(i, j+1);
                                click(i+1, j+1);
                                click(i+1, j);
                            }
                            if (j == height-1)
                            {
                                click(i-1, j);
                                click(i-1, j-1);
                                click(i, j-1);
                                click(i+1, j-1);
                                click(i+1, j);
                            }
                        }
                        if (i == 0)
                        {
                            if (j > 0 && j < height-1)
                            {
                                click(i, j-1);
                                click(i, j+1);
                                click(i+1, j);
                                click(i+1, j-1);
                                click(i+1, j+1);
                            }
                            if (j == 0)
                            {
                                click(i, j+1);
                                click(i+1, j);
                                click(i+1, j+1);
                            }
                            if (j == height-1)
                            {
                                click(i, j-1);
                                click(i+1, j);
                                click(i+1, j-1);
                            }
                        }
                        if (i == width-1)
                        {
                            if (j > 0 && j < height-1)
                            {
                                click(i-1, j);
                                click(i-1, j-1);
                                click(i-1, j+1);
                                click(i, j-1);
                                click(i, j+1);
                            }
                            if (j == 0)
                            {
                                click(i-1, j);
                                click(i-1, j+1);
                                click(i, j+1);
                            }
                            if (j == height-1)
                            {
                                click(i-1, j);
                                click(i-1, j-1);
                                click(i, j-1);
                            }
                        }
                    }
                }
            }
        }

        draw();
    }
}


MyTable::MyTable(QMainWindow *parent)
{
    parent->setStyleSheet("background: #323232; color: #fdd700;");
    parent->setMinimumWidth(720);
    parent->setMinimumHeight(540);
    parent->setMaximumWidth(720);
    parent->setMaximumHeight(540);
    parent->resize(720, 540);

    score_box = new QLabel(parent);
    score_box->resize(200, 40);
    score_box->move(440, 20);
    score_box->setText("0");
    score_box->show();
    score_box->setStyleSheet("background: #202020; color: #fdd700;");
    score_box->setFont(QFont("Helvetica", 16));
    score_box->setAlignment(Qt::AlignCenter);

    newgame = new QPushButton(parent);
    newgame->resize(160, 40);
    newgame->move(80, 20);
    newgame->setText("Новая игра");
    newgame->show();
    newgame->setFont(QFont("Helvetica", 16));
    QObject::connect(newgame, &QPushButton::clicked, [&]{NewGame();});

    bckgrnd = new QWidget(parent);
    bckgrnd->resize(80, 40);
    bckgrnd->move(320, 20);
    bckgrnd->setStyleSheet("background: #6495ed");

    flagButton = new QPushButton(parent);
    flagButton->resize(76, 36);
    flagButton->move(322, 22);
    flagButton->setFont(QFont("Helvetica", 16));
    flagButton->setText("Флаги");
    flagButton->show();
    QObject::connect(flagButton, QPushButton::clicked, [&]{if (flags == true){flags = false; bckgrnd->hide();}else{flags = true; bckgrnd->show();}});

    boxes.resize(width);
    for (int i = 0; i < width; i++)
        boxes[i].resize(height);

    for (int i = 0; i < boxes.size(); i++)
        for (int j = 0; j < boxes[i].size(); j++)
        {
            boxes[i][j] = new QPushButton(parent);
            boxes[i][j]->resize(40, 40);
            boxes[i][j]->move(20+i*40, 80+j*40);
            boxes[i][j]->show();
        }

    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
        {
            QObject::connect(boxes[i][j], &QPushButton::clicked, [i, j, this]{this->click(i, j);});
        }

    field.resize(width);
    for (int i = 0; i < width; i++)
        field[i].resize(height);

    NewGame();
}
