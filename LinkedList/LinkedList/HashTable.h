#pragma once
/*
	Analysis of hashing is based on loading factor.
		Loading factor = n/size
*/
class HNode {
public:
	int data;
	HNode* next = nullptr;
	HNode();
	HNode(int val);
};
class HashTable
{
private:
	HNode** table;
	int size = 10;
	// Chaining Collision handling methods
	int hashmod(int key);
	void InsertChaining(int key);
	int SearchChaining(int key);

	// Linear probing collision handling methods
	int hashprob(int key);
	int LinearProbe(int H[], int key);
	void InsertProbe(int H[], int key);
	int SearchProbe(int H[], int key);

	// Quadratic probing collision handling methods
	int hashquad(int key);
	int QuadraticProbe(int H[], int key);
	void InsertQuadratic(int H[], int key);
	int SearchQuadratic(int H[], int key);

	// Double Hashing collision handling methods
	int hashdub(int key);
	int PrimeHash(int key);
	int DoubleHash(int H[], int key);
	void InsertDub(int H[], int key);
	int SearchDub(int H[], int key);


public:
	void runChaining();
	HashTable();
	~HashTable();
};

