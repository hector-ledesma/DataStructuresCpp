#pragma once
#include "LinkedList.h"
class Queue2
{
private:
	Node* head;
	Node* tail;
public:
	Queue2();
	void queue(int x);
	int dequeue();
	void Display();
};

