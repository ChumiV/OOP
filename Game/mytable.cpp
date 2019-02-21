#include "mytable.h"


void MyTable::draw()
{
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
        {
            if (ms.Field()[i][j].type == open)
            {
                if (ms.Field()[i][j].bomb == false)
                {
                    if (ms.Field()[i][j].value > 0)
                    {
                        boxes[i][j]->setStyleSheet("background: #fdd700; color: #202020;");
                        boxes[i][j]->setFont(QFont("Helvetica", 16));
                        boxes[i][j]->setText(QString::number(ms.Field()[i][j].value));
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
            if (ms.Field()[i][j].type == close)
            {
                boxes[i][j]->setStyleSheet("");
                boxes[i][j]->setText("");
            }
            if (ms.Field()[i][j].type == flag)
            {
                boxes[i][j]->setStyleSheet("background: #6495ed");
                boxes[i][j]->setText("");
            }
        }

    score_box->setText(QString::number(ms.Score()));
}

MyTable::MyTable(QMainWindow *parent)
{
    widget = new QWidget(parent);

    widget->setStyleSheet("background: #323232; color: #fdd700;");
    widget->setMinimumWidth(720);
    widget->setMinimumHeight(540);
    widget->setMaximumWidth(720);
    widget->setMaximumHeight(540);
    widget->resize(720, 540);

    score_box = new QLabel(widget);
    score_box->resize(200, 40);
    score_box->move(440, 20);
    score_box->setText("0");
    score_box->show();
    score_box->setStyleSheet("background: #202020; color: #fdd700;");
    score_box->setFont(QFont("Helvetica", 16));
    score_box->setAlignment(Qt::AlignCenter);

    newgame = new QPushButton(widget);
    newgame->resize(160, 40);
    newgame->move(80, 20);
    newgame->setText("Новая игра");
    newgame->show();
    newgame->setFont(QFont("Helvetica", 16));
    QObject::connect(newgame, &QPushButton::clicked, [&]{ms.NewGame(); draw();});

    bckgrnd = new QWidget(widget);
    bckgrnd->resize(80, 40);
    bckgrnd->move(320, 20);
    bckgrnd->setStyleSheet("background: #6495ed");
    bckgrnd->hide();

    flagButton = new QPushButton(widget);
    flagButton->resize(76, 36);
    flagButton->move(322, 22);
    flagButton->setFont(QFont("Helvetica", 16));
    flagButton->setText("Флаги");
    flagButton->show();
    QObject::connect(flagButton, QPushButton::clicked, [&]{if (ms.Flags() == true){ms.SetFlags(false); bckgrnd->hide();}else{ms.SetFlags(true); bckgrnd->show();}  draw();});

    boxes.resize(width);
    for (int i = 0; i < width; i++)
        boxes[i].resize(height);

    for (int i = 0; i < boxes.size(); i++)
        for (int j = 0; j < boxes[i].size(); j++)
        {
            boxes[i][j] = new QPushButton(widget);
            boxes[i][j]->resize(40, 40);
            boxes[i][j]->move(20+i*40, 80+j*40);
            boxes[i][j]->show();
        }

    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
        {
            QObject::connect(boxes[i][j], &QPushButton::clicked, [i, j, this]{this->ms.click(i, j); draw();});
        }

    draw();
}

void MyTable::show()
{
    widget->show();
}

void MyTable::hide()
{
    widget->hide();
}
