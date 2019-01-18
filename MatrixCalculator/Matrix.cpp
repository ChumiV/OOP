#include "Matrix.h"

Matrix::Matrix()
{}

Matrix::Matrix(unsigned int rows)
{
	set_size(rows, rows);

	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			(i == j) ? mat[i][j] = 1 : mat[i][j] = 0;
		}
	}
}

Matrix::Matrix(unsigned int rows, unsigned int columns)
{
	set_size(rows, columns);
}

/*Matrix::Matrix(Matrix &&matrix) //присваивания
{
	set_size(matrix.rows(), matrix.columns());

	for (int i = 0; i < rows(); i++)
	{
		for (int j = 0; j < columns(); j++)
		{
			mat[i][j] = matrix.element(i, j);
		}
	}
}*/

/*Matrix::Matrix(Matrix &matrix) //копирования
{
	*this = matrix; 
}
*/
Matrix::~Matrix()
{}

unsigned int Matrix::rows() const
{
	return mat.size();
}

unsigned int Matrix::columns() const
{
	return mat[0].size();
}

float Matrix::element(unsigned int i, unsigned int j) const
{
	return mat[i][j];
}

void Matrix::set_size(unsigned int rows, unsigned int columns)
{
	mat.resize(rows);
	for (int i = 0; i < mat.size(); i++)
		mat[i].resize(columns);
}

void Matrix::set_element(unsigned int row, unsigned int column, float data)
{
	mat[row][column] = data;
}

Matrix Matrix::transp()
{
	Matrix temp_mat;
	temp_mat.set_size(columns(), rows());

    for (int i = 0; i < temp_mat.rows(); i++)
	{
        for (int j = 0; j < temp_mat.columns(); j++)
        {
            temp_mat.mat[i][j] = mat[j][i];
		}
	}

	return temp_mat;
}

Matrix Matrix::minor(unsigned int row, unsigned int column)
{
	Matrix temp_mat(rows() - 1, columns() - 1);

	int i = 0, j = 0;

	for (int a = 0; a < rows(); a++)
	{
		if (a != row)
		{

			for (int b = 0; b < columns(); b++)
			{
				if (b != column)
				{
					temp_mat.set_element(i, j, element(a, b));
					j += 1;
				}
			}

			j = 0;
			i += 1;
		}
	}

	return temp_mat;
}

float Matrix::determinant()
{
	int det = 0;

	if (columns() == rows())
	{
		if (rows() == 1)
			det = mat[0][0];
		else
		{
			if (rows() == 2)
				det = (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]);
			else
			{
				int k = 1;

				for (int i = 0; i < rows(); i++)
				{
					det = det + k * mat[i][0] * minor(i, 0).determinant();
					k *= -1;
				}
			}
		}
	}

	return det;
}

Matrix Matrix::operator + (const Matrix &matrix)
{
    Matrix nmat;

	if ((rows() == matrix.rows()) && (columns() == matrix.columns()))
	{
        nmat.set_size(rows(), columns());

		for (int i = 0; i < rows(); i++)
		{
			for (int j = 0; j < columns(); j++)
			{
                nmat.mat[i][j] = mat[i][j] + matrix.mat[i][j];
			}
		}
    }

	return nmat;
}

Matrix Matrix::operator - (const Matrix &matrix)
{
	Matrix nmat;
	if ((rows() == matrix.rows()) && (columns() == matrix.columns()))
	{
		nmat.set_size(rows(), columns());

		for (int i = 0; i < rows(); i++)
		{
			for (int j = 0; j < columns(); j++)
			{
                nmat.mat[i][j] = mat[i][j] - matrix.mat[i][j];
			}
		}
	}

	return nmat;
}

Matrix Matrix::operator * (float n)
{
	Matrix nmat;

	nmat.set_size(rows(), columns());

	for (int i = 0; i < rows(); i++)
	{
		for (int j = 0; j < columns(); j++)
		{
			nmat.set_element(i, j, (element(i, j) * n));
		}
	}

	return nmat;
}

Matrix Matrix::operator * (const Matrix &matrix)
{
	Matrix nmat;
	if (columns() == matrix.rows())
	{
		nmat.set_size(rows(), matrix.columns());

		for (int i = 0; i < nmat.rows(); i++)
		{
			for (int j = 0; j < nmat.columns(); j++)
			{
				for (int k = 0; k < matrix.rows(); k++)
					nmat.set_element(i, j, nmat.element(i, j) + mat[i][k] * matrix.element(k, j));
			}
		}
	}

	return nmat;
}

/*Matrix & Matrix::operator = (Matrix &matrix)
{
	if (this != &matrix)
	{
		mat.clear();

		set_size(matrix.rows(), matrix.columns());

		for (int i = 0; i < rows(); i++)
		{
			for (int j = 0; j < columns(); j++)
			{
				//mat[i][j] = matrix.element(i, j);
				mat[i][j] = matrix.mat[i][j];
			}
		}
	}
	return *this;
}

Matrix & Matrix::operator = (Matrix &&matrix)
{
	if (this == &matrix)
		return *this;
	else
	{
		delete[] & mat;

		set_size(matrix.rows(), matrix.columns());

		for (int i = 0; i < rows(); i++)
		{
			for (int j = 0; j < columns(); j++)
			{
				mat[i][j] = matrix.element(i, j);
			}
		}
	}
	return *this;
}*/

void Matrix::set_matrix(const Matrix &matrix)
{
    set_size(matrix.rows(), matrix.columns());

    for (int i = 0; i < rows(); i++)
    {
        for (int j = 0; j < columns(); j++)
        {
            mat[i][j] = matrix.mat[i][j];
        }
    }
}
