#pragma once
class DiagonalMatrix {
private:
	int A[10] = { 0 };
	int n;
public:
	DiagonalMatrix(int i);
	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	~DiagonalMatrix();
};