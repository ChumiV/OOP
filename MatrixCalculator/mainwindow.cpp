#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "additionalfunctions.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    a.set_size(1, 1);
    b.set_size(1, 1);
    c.set_size(1, 1);

    MatrixToTable(a, ui->tableWidgetA);
    MatrixToTable(b, ui->tableWidgetB);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_rowsA_valueChanged(int arg1)
{
    a.set_size(arg1, a.columns());
    MatrixToTable(a, ui->tableWidgetA);

    if ((a.columns() == b.columns()) && (a.rows() == b.rows()))
    {
        ui->pushButton_add->show();
        ui->pushButton_min->show();
    }
    else
    {
        ui->pushButton_add->hide();
        ui->pushButton_min->hide();
    }

    if (a.columns() == b.rows())
        ui->pushButton_mul->show();
    else
        ui->pushButton_mul->hide();

    if (a.columns() == a.rows())
    {
        ui->pushButton_detA->show();
        ui->label_detA->show();
    }
    else
    {
        ui->pushButton_detA->hide();
        ui->label_detA->hide();
    }
}

void MainWindow::on_spinBox_columnsA_valueChanged(int arg1)
{
    a.set_size(a.rows(), arg1);
    MatrixToTable(a, ui->tableWidgetA);

    if ((a.columns() == b.columns()) && (a.rows() == b.rows()))
    {
        ui->pushButton_add->show();
        ui->pushButton_min->show();
    }
    else
    {
        ui->pushButton_add->hide();
        ui->pushButton_min->hide();
    }

    if (a.columns() == b.rows())
        ui->pushButton_mul->show();
    else
        ui->pushButton_mul->hide();

    if (a.columns() == a.rows())
    {
        ui->pushButton_detA->show();
        ui->label_detA->show();
    }
    else
    {
        ui->pushButton_detA->hide();
        ui->label_detA->hide();
    }
}

void MainWindow::on_spinBox_rowsB_valueChanged(int arg1)
{
    b.set_size(arg1, b.columns());
    MatrixToTable(b, ui->tableWidgetB);

    if ((a.columns() == b.columns()) && (a.rows() == b.rows()))
    {
        ui->pushButton_add->show();
        ui->pushButton_min->show();
    }
    else
    {
        ui->pushButton_add->hide();
        ui->pushButton_min->hide();
    }

    if (a.columns() == b.rows())
        ui->pushButton_mul->show();
    else
        ui->pushButton_mul->hide();

    if (b.columns() == b.rows())
    {
        ui->pushButton_detB->show();
        ui->label_detB->show();
    }
    else
    {
        ui->pushButton_detB->hide();
        ui->label_detB->hide();
    }
}

void MainWindow::on_spinBox_columnsB_valueChanged(int arg1)
{
    b.set_size(b.rows(), arg1);
    MatrixToTable(b, ui->tableWidgetB);

    if ((a.columns() == b.columns()) && (a.rows() == b.rows()))
    {
        ui->pushButton_add->show();
        ui->pushButton_min->show();
    }
    else
    {
        ui->pushButton_add->hide();
        ui->pushButton_min->hide();
    }

    if (a.columns() == b.rows())
        ui->pushButton_mul->show();
    else
        ui->pushButton_mul->hide();

    if (b.columns() == b.rows())
    {
        ui->pushButton_detB->show();
        ui->label_detB->show();
    }
    else
    {
        ui->pushButton_detB->hide();
        ui->label_detB->hide();
    }
}

void MainWindow::on_pushButton_tranA_clicked()
{
    TableToMatrix(ui->tableWidgetA, a);

    a = a.transp();

    ui->spinBox_rowsA->setValue(a.rows());
    ui->spinBox_columnsA->setValue(a.columns());

    MatrixToTable(a, ui->tableWidgetA);
}

void MainWindow::on_pushButton_detA_clicked()
{
    TableToMatrix(ui->tableWidgetA, a);
    ui->label_detA->setText(QString::number(a.determinant()));
}

void MainWindow::on_pushButton_detB_clicked()
{
    TableToMatrix(ui->tableWidgetB, b);
    ui->label_detB->setText(QString::number(b.determinant()));
}

void MainWindow::on_pushButton_detC_clicked()
{
    if (c.columns() == c.rows())
    {
        ui->label_detC->show();
        ui->label_detC->setText(QString::number(c.determinant()));
    }
    else
        ui->label_detC->hide();
}

void MainWindow::on_pushButton_tranB_clicked()
{
    TableToMatrix(ui->tableWidgetB, b);

    b = b.transp();

    ui->spinBox_rowsB->setValue(b.rows());
    ui->spinBox_columnsB->setValue(b.columns());

    MatrixToTable(b, ui->tableWidgetB);
}

void MainWindow::on_pushButton_add_clicked()
{
    TableToMatrix(ui->tableWidgetA, a);
    TableToMatrix(ui->tableWidgetB, b);

    c = a+b;

    MatrixToTable(c, ui->tableWidgetC);

    if (c.rows() == c.columns())
    {
        ui->pushButton_detC->show();
        ui->label_detC->show();
    }
    else
    {
        ui->pushButton_detC->hide();
        ui->label_detC->hide();
    }
}

void MainWindow::on_pushButton_min_clicked()
{
    TableToMatrix(ui->tableWidgetA, a);
    TableToMatrix(ui->tableWidgetB, b);

    c = a-b;

    MatrixToTable(c, ui->tableWidgetC);

    if (c.rows() == c.columns())
    {
        ui->pushButton_detC->show();
        ui->label_detC->show();
    }
    else
    {
        ui->pushButton_detC->hide();
        ui->label_detC->hide();
    }
}

void MainWindow::on_pushButton_mul_clicked()
{
    TableToMatrix(ui->tableWidgetA, a);
    TableToMatrix(ui->tableWidgetB, b);

    c = a*b;

    MatrixToTable(c, ui->tableWidgetC);

    if (c.rows() == c.columns())
    {
        ui->pushButton_detC->show();
        ui->label_detC->show();
    }
    else
    {
        ui->pushButton_detC->hide();
        ui->label_detC->hide();
    }
}

void MainWindow::on_pushButton_AtoB_clicked()
{
    TableToMatrix(ui->tableWidgetA, a);
    b = a;

    ui->spinBox_rowsB->setValue(b.rows());
    ui->spinBox_columnsB->setValue(b.columns());

    MatrixToTable(b, ui->tableWidgetB);
}

void MainWindow::on_pushButton_CtoB_clicked()
{
    TableToMatrix(ui->tableWidgetC, c);
    b = c;

    ui->spinBox_rowsB->setValue(b.rows());
    ui->spinBox_columnsB->setValue(b.columns());

    MatrixToTable(b, ui->tableWidgetB);
}

void MainWindow::on_pushButton_CtoA_clicked()
{
    TableToMatrix(ui->tableWidgetC, c);
    a = c;

    ui->spinBox_rowsA->setValue(a.rows());
    ui->spinBox_columnsA->setValue(a.columns());

    MatrixToTable(a, ui->tableWidgetA);
}

void MainWindow::on_pushButton_BtoA_clicked()
{
    TableToMatrix(ui->tableWidgetB, b);
    a = b;

    ui->spinBox_rowsA->setValue(a.rows());
    ui->spinBox_columnsA->setValue(a.columns());

    MatrixToTable(a, ui->tableWidgetA);
}
