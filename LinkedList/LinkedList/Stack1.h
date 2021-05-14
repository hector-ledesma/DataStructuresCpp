#pragma once
// Stack1 will use an array,we'll make a Stack2 for linked list
class Stack1 {
	int size;
	int top;
	char* s;
public:
	Stack1(int sz);
	void Display();
	void push(char x);
	char pop();

	char peek(int index);
	char stackTop();
	bool isEmpty();
	bool isFull();

	int preOut(char x);
	int preIn(char x);
	bool isOperand(char x);
	char* InToPost(const char* in);
	int eval(char* post);
};

