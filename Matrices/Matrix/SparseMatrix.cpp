#include <iostream>
#include "SparseMatrix.h"

Sparse::Sparse() {
	// We need dimensions row and columns
	//		as well as number of non-zero elements.

	std::cout << "Enter Dimensions m: ";
	std::cin >> m;
	std::cout << "n: ";
	std::cin >> n;

	std::cout << "How many non-zero elements: ";
	std::cin >> num;

	ele = new Element[num];

	// Get elements from user input.
	for (int i = 0; i < num; i++) {
		Element e = Element();
		std::cout << "i: ";
		std::cin >> e.i;
		e.i--;
		std::cout << "j: ";
		std::cin >> e.j;
		e.j--;
		std::cout << "value: ";
		std::cin >> e.x;
		ele[i] = e;
	}
}

Sparse::~Sparse() {
	delete[]ele;
	ele = NULL;
}

void Sparse::Display() {
	int i, j, k = 0;
	std::cout << std::endl;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (i == ele[k].i && j == ele[k].j)
				std::cout << ele[k++].x << " ";
			else
				std::cout << "0 ";
		}
		std::cout << std::endl;
	}
}