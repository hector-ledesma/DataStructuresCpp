#pragma once
class HNode {
public:
	int data;
	HNode* next = nullptr;
	HNode();
	HNode(int val);
};
class HashTable
{
public:
	HNode** table;
	HashTable();
	void runChaining();
	int hashmod(int key);
	void InsertChaining(int key);
	int SearchChaining(int key);
	~HashTable();
};

