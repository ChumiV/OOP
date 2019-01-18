#include "node.h"

Node::Node()
{
    background = new QWidget;
    value = new QLabel(background);

    value->setAlignment(Qt::AlignCenter);

    background->resize(40, 20);
    value->resize(36, 16);
    value->move(2, 2);

    value->setStyleSheet(unhlgt);
    background->setStyleSheet(unhlgt);
}

Node::Node(QWidget *parent, const QString &data)
{
    background = new QWidget(parent);
    value = new QLabel(data, background);

    value->setAlignment(Qt::AlignCenter);

    background->resize(40, 20);
    value->resize(36, 16);
    value->move(2, 2);

    value->setStyleSheet(unhlgt);
    background->setStyleSheet(unhlgt);
}

Node::Node(QWidget *parent)
{
    background = new QWidget(parent);
    value = new QLabel(background);

    value->setAlignment(Qt::AlignCenter);

    background->resize(40, 20);
    value->resize(36, 16);
    value->move(2, 2);

    value->setStyleSheet(unhlgt);
    background->setStyleSheet(unhlgt);
}

void Node::setValue(const QString &data)
{
    value->setText(data);
}

void Node::light()
{
    background->setStyleSheet(hlgt);
}

void Node::dark()
{
     background->setStyleSheet(unhlgt);
}

void Node::highlight()
{
    if (background->styleSheet() == unhlgt)
        light();
    else
        dark();
}

void Node::show()
{
    background->show();
    value->show();
}

void Node::move(int x, int y)
{
    background->move(x, y);
}

int Node::x()
{
    return background->x();
}

int Node::y()
{
    return background->y();
}

int Node::height()
{
    return background->height();
}

int Node::width()
{
    return background->width();
}
