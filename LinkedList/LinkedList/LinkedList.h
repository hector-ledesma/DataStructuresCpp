#pragma once
#include <iostream>
class Node {
public:
	int data;
	// Define it as null here so we don't have to do so every time it's created.
	Node* next = NULL;
};

class LinkedList {
public:
	Node* head;
	LinkedList(int A[], int n);
	~LinkedList();

	void Display();
};