#include "mainwindow.h"
#include <QApplication>
#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    calculator c(&w);

    QObject::connect(&c, &calculator::updHistory, [&]{c.addHistory();});
    QObject::connect(&c, &calculator::newSolution, [&]{c.updateHistory();});
    QObject::connect(&c, &calculator::valueIsChange, [&]{c.outputValue();});
    QObject::connect(c.buttons[8], &QPushButton::clicked, [&]{c.change(7);});
    QObject::connect(c.buttons[9], &QPushButton::clicked, [&]{c.change(8);});
    QObject::connect(c.buttons[10], &QPushButton::clicked, [&]{c.change(9);});
    QObject::connect(c.buttons[12], &QPushButton::clicked, [&]{c.change(4);});
    QObject::connect(c.buttons[13], &QPushButton::clicked, [&]{c.change(5);});
    QObject::connect(c.buttons[14], &QPushButton::clicked, [&]{c.change(6);});
    QObject::connect(c.buttons[16], &QPushButton::clicked, [&]{c.change(1);});
    QObject::connect(c.buttons[17], &QPushButton::clicked, [&]{c.change(2);});
    QObject::connect(c.buttons[18], &QPushButton::clicked, [&]{c.change(3);});
    QObject::connect(c.buttons[21], &QPushButton::clicked, [&]{c.change(0);});
    QObject::connect(c.buttons[20], &QPushButton::clicked, [&]{c.changeSign();});
    QObject::connect(c.buttons[22], &QPushButton::clicked, [&]{if (c.dotIsClicked == 0) c.dotIsClicked = -1;});
    QObject::connect(c.buttons[3], &QPushButton::clicked, [&]{c.del();});
    QObject::connect(c.buttons[23], &QPushButton::clicked, [&]{c.solut();});
    QObject::connect(c.buttons[0], &QPushButton::clicked, [&]{if (c.temp.type == -1){c.goStack(); c.temp.type = 9; c.solut();}});
    QObject::connect(c.buttons[1], &QPushButton::clicked, [&]{if (c.temp.type == -1){c.goStack(); c.temp.type = 8; c.solut();}});
    QObject::connect(c.buttons[2], &QPushButton::clicked, [&]{if (c.temp.type == -1){c.goStack(); c.temp.type = 7; c.solut();}});
    QObject::connect(c.buttons[4], &QPushButton::clicked, [&]{if (c.temp.type == -1){c.goStack(); c.temp.type = 6; c.solut();}});
    QObject::connect(c.buttons[5], &QPushButton::clicked, [&]{if (c.temp.type == -1){c.goStack(); c.temp.type = 5; c.solut();}});
    QObject::connect(c.buttons[6], &QPushButton::clicked, [&]{if (c.temp.type == -1){c.goStack(); c.temp.type = 4; c.goStack();}});
    QObject::connect(c.buttons[7], &QPushButton::clicked, [&]{if (c.temp.type == -1){c.goStack(); c.temp.type = 3; c.goStack();}});
    QObject::connect(c.buttons[11], &QPushButton::clicked, [&]{if (c.temp.type == -1){c.goStack(); c.temp.type = 2; c.goStack();}});
    QObject::connect(c.buttons[15], &QPushButton::clicked, [&]{if (c.temp.type == -1){c.goStack(); c.temp.type = 1; c.goStack();}});
    QObject::connect(c.buttons[19], &QPushButton::clicked, [&]{if (c.temp.type == -1){c.goStack(); c.temp.type = 0; c.goStack();}});

    return a.exec();
}
