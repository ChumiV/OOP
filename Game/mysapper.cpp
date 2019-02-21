#include "mysapper.h"

MySapper::MySapper()
{
    field.resize(width);
    for (int i = 0; i < width; i++)
        field[i].resize(height);

    NewGame();

    flags = false;
}


void MySapper::GameOver()
{
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
        {
            field[i][j].type = open;
        }

    end_game = true;
}

void MySapper::bomb_random(int i, int j)
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

void MySapper::bomb_around(int i, int j)
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

void MySapper::NewGame()
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
    score = 0;
}

void MySapper::click(int i, int j)
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
    }
}

vector <vector <box>> MySapper::Field()
{
    return field;
}

bool MySapper::New_Game()
{
    return new_game;
}

bool MySapper::End_Game()
{
    return end_game;
}

bool MySapper::Flags()
{
    return flags;
}

unsigned int MySapper::Score()
{
    return score;
}

void MySapper::SetFlags(bool b)
{
    flags = b;
}
