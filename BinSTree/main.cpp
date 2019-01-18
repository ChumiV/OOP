#include "mainwindow.h"
#include "binstree.h"
#include <QApplication>
#include <QtWidgets>
#include <QVector>
#include <QString>
#include <QPushButton>
#include <QScrollArea>
#include <node.h>
#include "menubarwindow.h"
#include "qbinstree.h"

void setMenu(QMenuBar &mnuBar, QWidget *w, QWidget *w1, QWidget *w2, QWidget *w3, QWidget *w4)
{
    QMenu *mnu = new QMenu("Menu");

    mnu->addAction("Создать дерево", w, SLOT(show()));
    mnu->addAction("Удалить дерево", w1, SLOT(show()));
    mnu->addSeparator();
    mnu->addAction("Вставить элемент", w2, SLOT(show()));
    mnu->addAction("Найти элемент", w3, SLOT(show()));
    mnu->addAction("Удалить элемент", w4, SLOT(show()));
    mnu->addSeparator();

    mnuBar.addMenu(mnu);
    mnuBar.resize(700, 20);
}

void setWindow(MainWindow &w)
{
    w.resize(700, 620);
    w.setMaximumWidth(700);
    w.setMaximumHeight(620);
    w.setMinimumWidth(700);
    w.setMinimumHeight(620);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    setWindow(w);
    w.show();

    QWidget *w1 = new QWidget();
    w1->show();

    QBinSTree bst(w1);

    QScrollArea *sa = new QScrollArea(&w);
    sa->resize(700,600);
    sa->move(0, 20);
    sa->show();
    sa->setWidget(w1);

    MenuBarWindow *crt = new MenuBarWindow(); //окно создания дерева
    MenuBarWindow *del = new MenuBarWindow(); //окно удаления элемента
    MenuBarWindow *del1 = new MenuBarWindow(); //окно удаления дерева
    MenuBarWindow *ins = new MenuBarWindow(); //окно вставки элемента
    MenuBarWindow *find = new MenuBarWindow(); //окно поиска элемента

    crt->createWindow();
    del->deleteWindow();
    del1->deleteWindow1();
    ins->insertWindow();
    find->findWindow();

    QMenuBar mnuBar;
    mnuBar.setParent(&w);
    setMenu(mnuBar, crt->w, del1->w, ins->w, find->w, del->w);
    mnuBar.show();

    QObject::connect(crt->pb, &QPushButton::clicked, [&](){bst.insertElement(crt->t->text().toInt());});
    QObject::connect(crt->t, &QLineEdit::returnPressed, [&](){bst.insertElement(crt->t->text().toInt());});
    QObject::connect(crt->pb, &QPushButton::clicked, [&](){crt->t->clear();});
    QObject::connect(crt->t, &QLineEdit::returnPressed, [&](){crt->t->clear();});

    QObject::connect(&bst, SIGNAL(treeIsChange()), &bst, SLOT(DrawIt()));

    QObject::connect(del->pb, &QPushButton::clicked, [&](){bst.deleteElement(del->t->text().toInt());});
    QObject::connect(del->t, &QLineEdit::returnPressed, [&](){bst.deleteElement(del->t->text().toInt());});
    QObject::connect(del->t, &QLineEdit::returnPressed, [&](){del->t->clear();});
    QObject::connect(del->pb, &QPushButton::clicked, [&](){del->t->clear();});

    QObject::connect(del1->pb, &QPushButton::clicked, [&](){bst.deleteAll();});
    QObject::connect(del1->pb, &QPushButton::clicked, del1->w, &QWidget::hide);

    QObject::connect(ins->pb, &QPushButton::clicked, [&](){bst.insertElement(ins->t->text().toInt());});
    QObject::connect(ins->t, &QLineEdit::returnPressed, [&](){bst.insertElement(ins->t->text().toInt());});
    QObject::connect(ins->pb, &QPushButton::clicked, [&](){ins->t->clear();});
    QObject::connect(ins->pb, &QPushButton::clicked, ins->w, &QWidget::hide);
    QObject::connect(ins->t, &QLineEdit::returnPressed, ins->w, &QWidget::hide);

    QObject::connect(find->pb, &QPushButton::clicked, [&](){bst.find(find->t->text().toInt());});
    QObject::connect(find->t, &QLineEdit::returnPressed, [&](){bst.find(find->t->text().toInt());});
    QObject::connect(find->pb, &QPushButton::clicked, [&](){find->t->clear();});
    QObject::connect(find->t, &QLineEdit::returnPressed, [&](){find->t->clear();});


    return a.exec();
}
