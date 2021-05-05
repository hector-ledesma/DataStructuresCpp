#pragma once
class LowTriMatrix {
private:
	int A[20] = { 0 };
	int n;
public:
	LowTriMatrix(int i);
	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	~LowTriMatrix();
};
