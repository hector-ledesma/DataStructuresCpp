#include <iostream>
#include "SparseMatrix.h"

Sparse::Sparse() {
	// We need dimensions row and columns
	//		as well as number of non-zero elements.

	/*std::cout << "Enter Dimensions m: ";
	std::cin >> m;
	std::cout << "n: ";
	std::cin >> n;

	std::cout << "How many non-zero elements: ";
	std::cin >> num;*/

	m = 5;
	n = 6;
	num = 4;

	ele = new Element[num];

	// Get elements from user input.
	/*for (int i = 0; i < num; i++) {
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
	}*/

	// I'll just hardcode these cause sheesh
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

Sparse* Sparse::add(Sparse* m1, Sparse* m2) {
	if (m1->m != m2->m || m1->n != m2->n) {
		std::cout << "Matrices dimensions do not match." << std::endl;
		return NULL;
	}
	
	Sparse* sum = new Sparse;
	// Doesn't matter which matrix we extract m and n for since they'll be the same.
	sum->m = m1->m;
	sum->n = m2->n;
	// Our array needs to be at least as big as the amount of 
	//		non-zero elements in both matrices
	sum->num = m1->num + m2->num;
	sum->ele = new Element[sum->num];

	// Indices:
	//	i -> traversing m1
	//	j -> traversing m2
	//	k -> traversin sum
	int i, j, k;
	i = j = k = 0;

	// We want to loop til we go through both matrices.
	while (i < m1->num && j < m2->num) {
		// If row for m1 is smaller, add it to sum.
		if (m1->ele[i].i < m2->ele[j].i)
			sum->ele[k++] = m1->ele[i++];
		// Else if row for m1 is larger, add m2 to sum.
		else if (m1->ele[i].i > m2->ele[j].i)
			sum->ele[k++] = m2->ele[j++];
		// Else if rows are the same, compare columns
		else {
			// If column for m1 is smaller, add it to sum.
			if (m1->ele[i].j < m2->ele[j].j)
				sum->ele[k++] = m1->ele[i++];
			// Else if column for m1 is larger, add m2 to sum.
			else if (m1->ele[i].j > m2->ele[j].j)
				sum->ele[k++] = m2->ele[j++];
			// Else if they're the same
			else {
				// Move m1 or m2 into sum[k].
				sum->ele[k] = m1->ele[i++];
				// Add the other element's value onto sum[k].x
				sum->ele[k++].x += m2->ele[j++].x;
			}
		}
	}

	// If i is less than num, then we have elements left in m1, move em in
	for (; i < m1->num; i++) sum->ele[k++] = m1->ele[i];

	// If j is less than num, then we have elements left in m2, move em in
	for (; j < m2->num; j++) sum->ele[k++] = m2->ele[j];

	return sum;
}