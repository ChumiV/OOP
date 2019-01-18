#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QTableWidget>
#include <QString>
#include "Matrix.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class MatrixCalculator;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_spinBox_rowsA_valueChanged(int arg1);

    void on_spinBox_columnsA_valueChanged(int arg1);

    void on_spinBox_rowsB_valueChanged(int arg1);

    void on_spinBox_columnsB_valueChanged(int arg1);

    void on_pushButton_tranA_clicked();

    void on_pushButton_detA_clicked();

    void on_pushButton_detB_clicked();

    void on_pushButton_detC_clicked();

    void on_pushButton_tranB_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_AtoB_clicked();

    void on_pushButton_CtoB_clicked();

    void on_pushButton_CtoA_clicked();

    void on_pushButton_BtoA_clicked();

private:
    Ui::MainWindow *ui;

    Matrix a, b, c;
};

#endif // MAINWINDOW_H
