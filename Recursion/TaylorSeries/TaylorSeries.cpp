// TaylorSeries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

double taylorLinear(double x, double n) {
	static double p = 1, f = 1;
	double r = 0;
	if (n == 0)
		return 1;

	r = taylorLinear(x, n - 1);
	p = p * x;
	f = f * n;
	return r + p / f;
}

double taylorHorner(double x, double n) {
	static double s;
	if (n == 0)
		return s;
	s = 1 + x / n*s;
	return taylorHorner(x, n - 1);
}

int main()
{
	std::cout << taylorHorner(1, 10);

}
