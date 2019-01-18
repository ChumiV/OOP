#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPushButton *button = new QPushButton("hfhf");

    button->show();

    //QObject::connect(button, SIGNAL(clicked(bool)), &a, SLOT(quit()));
    QObject::connect(button, SIGNAL(clicked(bool)), button, SLOT(hide()));

    return a.exec();
}
