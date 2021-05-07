#pragma once
class Term {
public:
	int coeff;
	int exp;
};
class Polynomial
{
public:
	int n;
	Term* terms;
	Polynomial(int nums);
	~Polynomial();
	void Display();

	static Polynomial* add(Polynomial* p1, Polynomial* p2);
};

