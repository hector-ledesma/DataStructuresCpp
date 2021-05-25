#pragma once
#include <iostream>
#include <vector>
class Heap
{
private:
	void swap(std::vector<int>& a, int i, int j);
public:
	void CreateHeap(std::vector<int>& vex, int A[], int n);
	void Insert(std::vector<int>& a, int key);
	void InsertInPlace(std::vector<int>& a, int n);
	int Delete(std::vector<int>& a, int n);
};

