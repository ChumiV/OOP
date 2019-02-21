#include "Complex.h"
#include <iostream>

using namespace std;

void view(Complex &c)
{
	if (c.Re() != 0)
	{
		cout << c.Re();

		if (c.Im() != 0)
		{
			if (c.Im() > 0)
				cout << "+";
		}
	}
	if (c.Im() != 0)
	{
		if (c.Im() == 1)
			cout << "i";
		else
			cout << c.Im() << "i";
	}
}

void main()
{
	Complex a(1, -1);
	Complex b(1, 4);

	view(a);

	cout << endl;

	cout << a.argument() << endl;

	system("pause");
}