#include "Complex.h"

Complex::Complex()
{
	x_ = 0;
	y_ = 0;
}

Complex::Complex(float x, float y)
{
	SetRe(x);
	SetIm(y);
}

void Complex::SetRe(float x)
{
	x_ = x;
}

void Complex::SetIm(float y)
{
	y_ = y;
}

float Complex::Re() const
{
	return x_;
}

float Complex::Im() const
{
	return y_;
}

float Complex::module() const
{
	return (sqrt(x_*x_ + y_*y_));
}

float Complex::argument() const
{
	return (atan(y_/x_));
}

Complex Complex::operator + (const Complex &c)
{
	return Complex(x_ + c.Re(), y_ + c.Im());
}

Complex Complex::operator - (const Complex &c)
{
	return Complex(x_ - c.Re(), y_ - c.Im());
}

Complex Complex::operator * (const Complex &c)
{
	return Complex(x_*c.Re() - y_ * c.Im(), x_*c.Im() + c.Re()*y_);
}

Complex Complex::operator / (const Complex &c)
{
	if ((c.Re() != 0) || (c.Im() != 0))
	{
		return Complex((x_*c.Re() + y_*c.Im()) / (c.Re()*c.Re() + c.Im()*c.Im()), (x_*c.Im() + y_*c.Re()) / (c.Re()*c.Re() + c.Im()*c.Im()));
	}
}