// TailHead.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void fun(int n) {
	if (n > 0) {
		printf("%d ", n);
		printf("");
		fun(n - 1);
	}
}

int main()
{
	int x = 3;

	fun(x);
	return 0;
}
