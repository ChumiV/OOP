#pragma once
#include <vector>
#include <math.h>

using namespace std;

class Matrix
{
private:
	vector <vector <float>> mat;

public:
	Matrix();

	Matrix(unsigned int rows);

    Matrix(unsigned int rows, unsigned int columns);

    //Matrix(Matrix &&matrix); //присваивания

    //Matrix(Matrix &matrix); //копирования

	~Matrix();

	unsigned int rows() const;

	unsigned int columns() const;

	float element(unsigned int i, unsigned int j) const;

	void set_size(unsigned int rows, unsigned int columns);

	void set_element(unsigned int row, unsigned int column, float data);

	Matrix transp();

	Matrix minor(unsigned int row, unsigned int column);

    void set_matrix(const Matrix &matrix);

	float determinant();

	Matrix operator + (const Matrix &matrix);

	Matrix operator - (const Matrix &matrix);

	Matrix operator * (float n);

	Matrix operator * (const Matrix &matrix);

//    Matrix & operator = (Matrix &matrix);

//    Matrix & operator = (Matrix &&matrix);
	


};

