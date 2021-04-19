// Honai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void honai(int n, int A, int B, int C) {
	if (n > 0)
	{
		honai(n - 1, A, C, B);
		std::cout << A << ", " << C << std::endl;
		honai(n - 1, B, A, C);
	}
}
int main()
{
	honai(4, 1, 2, 3);
}
