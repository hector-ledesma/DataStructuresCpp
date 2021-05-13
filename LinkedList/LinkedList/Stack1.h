#pragma once
// Stack1 will use an array,we'll make a Stack2 for linked list
class Stack1 {
	int size;
	int top;
	int* s;
public:
	Stack1(int sz);
	void Display();
	void push(int x);
	int pop();

	int peek(int index);
	int stackTop();
	bool isEmpty();
	int isFull();

};

