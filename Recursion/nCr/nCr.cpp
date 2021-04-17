// nCr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int fact(int n) {
	if (n == 0) return 1;
	return fact(n - 1) * n;
}

int nCr(int n, int r) {
	int num, den;

	num = fact(n);
	den = fact(r) * fact(n - r);

	return num / den;
}

int nCrPascal(int n, int r) {
	if (n == r || r == 0) return 1;
	return nCrPascal(n - 1, r - 1) + nCrPascal(n - 1, r);
}

int main()
{
	std::cout << nCr(12, 3) << std::endl;
	std::cout << nCrPascal(12, 3) << std::endl;

}
