#include <iostream>
#include "LowTriMatrix.h"

LowTriMatrix::LowTriMatrix(int i) {
	n = i;
}

void LowTriMatrix::Set(int i, int j, int x) {
	if (i >= j)
		A[i * (i - 1) / 2 + j - 1] = x;
}

int LowTriMatrix::Get(int i, int j) {
	if (i >= j)
		return A[i*(i-1)/2+j-1];
	else
		return 0;
}

void LowTriMatrix::Display() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= j)
				std::cout << A[i * (i - 1) / 2 + j - 1] << " ";
			else
				std::cout << 0 << " ";
		}
		std::cout << std::endl;
	}
}

LowTriMatrix::~LowTriMatrix() {
	std::cout << "Lower Triangle matrix destroyed. No heap data to deallocate" << std::endl;
}