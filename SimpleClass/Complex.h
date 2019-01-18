#pragma once
class Complex
{
	float x_, y_;
public:
	Complex();
	Complex(float x, float y);
	void Complex::SetRe(float x);
	void Complex::SetIm(float y);
	float Complex::Re() const;
	float Complex::Im() const;

	Complex Complex::operator + (const Complex &c);
	Complex Complex::operator - (const Complex &c);
	Complex Complex::operator * (const Complex &c);
	Complex Complex::operator / (const Complex &c);
};

