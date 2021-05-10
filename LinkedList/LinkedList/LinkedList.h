#pragma once
#include <iostream>
class Node {
public:
	int data;
	// Define it as null here so we don't have to do so every time it's created.
	Node* next = NULL;

	Node();
	Node(int ns);
};

class LinkedList {
public:
	Node* head;
	int id;
	LinkedList(int A[], int n, int num);
	~LinkedList();

	void Display();
	void RDisplay(Node* p);
	int count();
	int sum();
	int max();

	Node* Search(int key);
	void Insert(int data, int pos);
	void InsertSorted(int data);
	int Delete(int pos);
	bool isSorted();
	void DeleteDupes();

	void ReverseArr();
	void ReverseSP(); // SP for Sliding Pointers.
	void ReverseRec(Node* q, Node* p);

	void Append(LinkedList &secondList);
	void Merge(LinkedList &secondList);

	bool isLoop();
	void makeCircular();
	void DisplayCircular();
};