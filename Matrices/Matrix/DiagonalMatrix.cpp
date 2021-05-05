#include <iostream>
#include "./DiagonalMatrix.h"

DiagonalMatrix::DiagonalMatrix(int i) {
	n = i;
}

void DiagonalMatrix::Set(int i, int j, int x) {
	if (i == j)
		A[i - 1] = x;
}

int DiagonalMatrix::Get(int i, int j) {
	if (i == j)
		return A[i - 1];
	else
		return 0;
}

void DiagonalMatrix::Display() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				std::cout << A[i] << " ";
			else
				std::cout << 0 << " ";
		}
		std::cout << std::endl;
	}
}

DiagonalMatrix::~DiagonalMatrix() {
	std::cout << "Diagonal matrix destroyed. No heap data to deallocate" << std::endl;
}