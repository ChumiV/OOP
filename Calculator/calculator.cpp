#include "calculator.h"

const int width = 75;
const int height = 20;
const int indent = 5;

void calculator::refreshHistory()
{
    int i = 0;

    for (auto &s: history)
    {
        s->resize(2*width, height);
        s->move(4*(width + indent), i*(height+indent));
        s->setAlignment(Qt::AlignCenter);
        s->setFont(QFont("Helvetica", 16));
        s->show();
        i++;
    }
}

void calculator::location()
{
    w->resize(4*(width+indent)+2*width, 7*(height+indent)-indent);
    w->setMaximumWidth(4*(width+indent)+2*width);
    w->setMaximumHeight(7*(height+indent)-indent);
    w->setMinimumWidth(4*(width+indent)+2*width);
    w->setMinimumHeight(7*(height+indent)-indent);

    l->resize(4*(width + indent) - indent, height);
    l->show();

    for (int i = 0; i < buttons.size(); i++)
    {
        buttons[i]->resize(width, height);
        buttons[i]->move(i%4*(width+indent), (i/4 + 1)*(height+indent));
        buttons[i]->show();
    }
}

calculator::calculator(QMainWindow *new_window)
{
    w = new_window;

    for (int i = 0; i < 7; i++)
    {
        history.push_back(new QLabel(w));
    }

    refreshHistory();

    buttons.push_back(new QPushButton("cos x", w));
    buttons.push_back(new QPushButton("sin x", w));
    buttons.push_back(new QPushButton("tan x", w));
    buttons.push_back(new QPushButton("C", w));
    buttons.push_back(new QPushButton("ln x", w));
    buttons.push_back(new QPushButton("exp x", w));
    buttons.push_back(new QPushButton("x^b", w));
    buttons.push_back(new QPushButton("÷", w));
    buttons.push_back(new QPushButton("7", w));
    buttons.push_back(new QPushButton("8", w));
    buttons.push_back(new QPushButton("9", w));
    buttons.push_back(new QPushButton("*", w));
    buttons.push_back(new QPushButton("4", w));
    buttons.push_back(new QPushButton("5", w));
    buttons.push_back(new QPushButton("6", w));
    buttons.push_back(new QPushButton("-", w));
    buttons.push_back(new QPushButton("1", w));
    buttons.push_back(new QPushButton("2", w));
    buttons.push_back(new QPushButton("3", w));
    buttons.push_back(new QPushButton("+", w));
    buttons.push_back(new QPushButton("±", w));
    buttons.push_back(new QPushButton("0", w));
    buttons.push_back(new QPushButton(",", w));
    buttons.push_back(new QPushButton("=", w));

    l = new QLabel(w);
    l->setAlignment(Qt::AlignCenter);
    l->setFont(QFont("Helvetica", 16));

    location();

    temp.value = 0;
    temp.type = -1;
    dotIsClicked = 0;

    l->setText(QString::number(temp.value));
}

void calculator::outputValue()
{
    l->setText(QString::number(temp.value));
}

void calculator::change(int num)
{
    temp.type = -1;

    if (dotIsClicked == 0)
        temp.value = temp.value*10 + num;
    else
    {
        temp.value += num * pow(10, dotIsClicked);
        dotIsClicked -= 1;
    }

    emit valueIsChange();
}

void calculator::changeSign()
{
    temp.type = -1;
    temp.value *= -1;

    emit valueIsChange();
}

void calculator::del()
{
    temp.value = 0;
    c.box.clear();
    dotIsClicked = 0;

    emit valueIsChange();
}

void calculator::solut()
{
    goStack();

    if (c.calculation())
    {
        l->setText("Ошибка");
    }
    else
    {
        temp = c.box.pop();
        emit valueIsChange();
    }



    c.box.clear();

    emit newSolution();
}

void calculator::goStack()
{
    emit updHistory();

    c.box.push(temp);

    dotIsClicked = 0;
    temp.value = 0;
}

void calculator::addHistory()
{
    bool c;

    for (auto &s: history)
    {
        if (!s->text().contains("="))
        {
            c = true;
            break;
        }
    }

    if (!c)
    {
        history[0]->hide();
        history.pop_front();
        history.push_back(new QLabel(w));

        refreshHistory();
    }


        for (auto &s: history)
        {
            if (!s->text().contains("="))
            {
                switch (temp.type)
                {
                case -1:
                    s->setText(s->text() + QString::number(temp.value));
                    break;
                case 0:
                     s->setText(s->text() + "+");
                    break;
                case 1:
                     s->setText(s->text() + "-");
                    break;
                case 2:
                     s->setText(s->text() + "*");
                    break;
                case 3:
                     s->setText(s->text() + "/");
                    break;
                case 4:
                     s->setText(s->text() + "^");
                    break;
                case 5:
                     s->setText("exp(" + s->text() + ")");
                    break;
                case 6:
                    s->setText("ln(" + s->text() + ")");
                    break;
                case 7:
                    s->setText("tan(" + s->text() + ")");
                    break;
                case 8:
                    s->setText("sin(" + s->text() + ")");
                    break;
                case 9:
                    s->setText("cos(" + s->text() + ")");
                    break;
                }
                break;
            }

    }
}

void calculator::updateHistory()
{
    for (auto &s: history)
    {
        if (!s->text().contains("="))
        {
            s->setText(s->text() + " = " + l->text());
            break;
        }

    }
}
