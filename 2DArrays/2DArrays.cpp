// 2DArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{

	int* B[3];
	int** C;
	int i, j;

	std::cout << sizeof B << std::endl;
	B[0] = (int*)malloc(4 * sizeof(int));
	B[1] = (int*)malloc(4 * sizeof(int));
	B[2] = (int*)malloc(4 * sizeof(int));
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++)
			std::cout << B[i][j];
		std::cout << std::endl;
	}

	std::cout << sizeof C << std::endl;
	C = (int**)malloc(3 * sizeof(int*));
	C[0] = (int*)malloc(4 * sizeof(int));
	C[0][0] = 1212;
	C[1] = (int*)malloc(4 * sizeof(int));
	C[2] = (int*)malloc(4 * sizeof(int));

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++)
			std::cout << C[i][j];
		std::cout << std::endl;
	}
}