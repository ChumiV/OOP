#ifndef ADDITIONALFUNCTIONS_H
#define ADDITIONALFUNCTIONS_H
#include "Matrix.h"
#include <QTableWidget>
#include <QLineEdit>
#include <exception.h>

void TableToMatrix(QTableWidget *&table, Matrix &matrix)
{
    int rows = table->rowCount();
    int cols = table->columnCount();

    matrix.set_size(rows, cols);
    try
    {
        for (int i =0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
            {
                bool ok;
                long double t = (table->item(i, j)->text()).toDouble(&ok);
                if (!ok)
                    throw Exception(10, "incorrec data");
                matrix.set_element(i, j, t);
             }
         }
    }
    catch (Exception error)
    {
            error.showErrorMsg();
    }
}

double ReadLineEdit(QLineEdit *&x)
{
    bool ok;
    double t = x->text().toDouble(&ok);
    if (!ok)
        throw Exception(10, "incorrec data");

   return t;
}

void MatrixToTable(Matrix &matrix, QTableWidget *&table)
{
    table->setRowCount(matrix.rows());
    table->setColumnCount(matrix.columns());

    for (auto i = 0; i<table->rowCount(); i++)
    {
        for (auto j = 0; j<table->columnCount(); j++)
        {
            QString str = QString::number(matrix.element(i, j), 'f', 2);
            table->setItem(i, j, new QTableWidgetItem(str));
        }
    }
}

#endif // EXTRAFUNCTION_H
