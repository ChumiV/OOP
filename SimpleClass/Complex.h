#pragma once
#include <math.h>

class Complex
{
	float x_, y_;
public:
	Complex();
	Complex(float x, float y);
	void SetRe(float x);
	void SetIm(float y);
	float Re() const;
	float Im() const;
	float module() const;
	float argument() const;

	Complex operator + (const Complex &c);
	Complex operator - (const Complex &c);
	Complex operator * (const Complex &c);
	Complex operator / (const Complex &c);
};