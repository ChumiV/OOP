#include "menubarwindow.h"

void MenuBarWindow::createWindow()
{
    w = new QWidget();
    w->resize(300,200);
    t = new QLineEdit(w);
    t->setAlignment(Qt::AlignCenter);
    t->resize(150,50);
    t->move(75, 50);
    pb = new QPushButton("Вставить узел", w);
    pb->resize(100, 25);
    pb->move(100, 125);
}

void MenuBarWindow::deleteWindow()
{
    w = new QWidget();
    w->resize(300,200);
    t = new QLineEdit(w);
    t->setAlignment(Qt::AlignCenter);
    t->resize(150,50);
    t->move(75, 50);
    pb = new QPushButton("Удалить узел", w);
    pb->resize(100, 25);
    pb->move(100, 125);

}

void MenuBarWindow::deleteWindow1()
{
    w = new QWidget();
    w->resize(300,200);
    l = new QLabel("Вы уверены, что хотите очистить дерево?", w);
    l->resize(275,50);
    l->move(50, 50);
    pb = new QPushButton("Да", w);
    pb->resize(100, 25);
    pb->move(100, 125);
}

void MenuBarWindow::insertWindow()
{
    w = new QWidget();
    w->resize(300,200);
    t = new QLineEdit(w);
    t->setAlignment(Qt::AlignCenter);
    t->resize(150,50);
    t->move(75, 50);
    pb = new QPushButton("Вставить узел", w);
    pb->resize(100, 25);
    pb->move(100, 125);
}

void MenuBarWindow::findWindow()
{
    w = new QWidget();
    w->resize(300,200);
    t = new QLineEdit(w);
    t->setAlignment(Qt::AlignCenter);
    t->resize(150,50);
    t->move(75, 50);
    pb = new QPushButton("Найти узел", w);
    pb->resize(100, 25);
    pb->move(100, 125);
}

