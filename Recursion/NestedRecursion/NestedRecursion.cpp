// NestedRecursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int fun(int n) {
	if (n > 100)
		return n - 10;
	return fun(fun(n + 11));
}

int main()
{
	int r;
	r = fun(95);
	std::cout << r << std::endl;
}
