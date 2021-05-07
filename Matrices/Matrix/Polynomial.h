#pragma once
class Term {
	int coeff;
	int exp;
};
class Polynomial
{
	int n;
	Term* terms;
	Polynomial(int nums);
	~Polynomial();
};

