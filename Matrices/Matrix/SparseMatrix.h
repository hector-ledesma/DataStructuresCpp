#pragma once
class Element {
public:
	int i, j, x;
};

class Sparse {
public:
	int m, n, num;
	Element* ele;
	Sparse();
	~Sparse();

	void Display();
	static Sparse* add(Sparse* m1, Sparse* m2);
};