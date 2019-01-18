#ifndef MENUBARWINDOW_H
#define MENUBARWINDOW_H

#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>

class MenuBarWindow : public QObject
{
    Q_OBJECT
public:
    QWidget *w = NULL;
    QLabel *l = NULL;
    QLineEdit *t = NULL;
    QPushButton *pb = NULL;

    void createWindow();
    void deleteWindow();
    void deleteWindow1();
    void insertWindow();
    void findWindow();

};




#endif // MENUBARWINDOW_H
