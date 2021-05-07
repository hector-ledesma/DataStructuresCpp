#include "Polynomial.h"
#include <iostream>

Polynomial::Polynomial(int nums) {
	n = nums;
}

Polynomial::~Polynomial() {
	delete[]terms;
}

void Polynomial::Display() {
	for (int i = 0; i < n; i++)
		std::cout << terms[i].coeff << "x^" << terms[i].exp << " + ";
	std::cout << std::endl;
}

// This is the same concept behind sparse matrices
Polynomial* Polynomial::add(Polynomial* p1, Polynomial* p2) {
	int i, j, k;
	i = j = k = 0;
	// The size of our new array will be the amount of elems in both polynomials
	int nums = p1->n + p2->n;
	Polynomial* sum = new Polynomial(nums);
	sum->terms = new Term[nums];

	// Loop til we finish going through one of the polynomials
	while (i < p1->n && j < p2->n) {
		// If p1's exponent is larger, add it to sum
		if (p1->terms[i].exp > p2->terms[j].exp)
			sum->terms[k++] = p1->terms[i++];
		// Else if p2's exponent is larger, add it
		else if (p1->terms[i].exp < p2->terms[j].exp)
			sum->terms[k++] = p2->terms[j++];
		// If exponents are equal, we can add the coefficients
		else {
			sum->terms[k] = p1->terms[i++];
			sum->terms[k++].coeff += p2->terms[j++].coeff;
		}
	}

	// And as usual, check which one has some juice left in it, and squeeze it out.
	for (; i < p1->n; i++) sum->terms[k++] = p1->terms[i];
	for (; j < p2->n; j++) sum->terms[k++] = p2->terms[j];
}