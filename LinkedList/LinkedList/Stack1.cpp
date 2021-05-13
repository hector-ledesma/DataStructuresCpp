#include "Stack1.h"
#include <iostream>

Stack1::Stack1(int sz) {
	top = -1;
	size = sz;
	s = new int[sz];
}

void Stack1::Display() {
	for (int i = top; i >= 0; i--)
		std::cout << s[i] << " ";
	std::cout << std::endl;
}
void Stack1::push(int x) {
	// Firs we want to check that the stack isn't full
	if (isFull())
		std::cout << "Stack overflow" << std::endl;
	else {
		top++;
		s[top] = x;
	}
}

int Stack1::pop() {
	int x = -1;

	// Check that array isn't empty
	if (isEmpty())
		std::cout << "Stack underflow" << std::endl;
	// If it isn't we want to extract the item currently at the top.
	else {
		x = s[top--];
	}

	return x;
}

// In a stack, the indices are in theory reversed.
// Our "first" element is not index 0, but the top.
// So how do we convert a human index 0 into the computer's last index?
// top - index
// Let's use human indexing for parameters meaning first item is index 1 not 0
// So formula will be:
//		top - index + 1
int Stack1::peek(int index) {
	// Calculate our index
	int i = top - index + 1;
	int x = -1;
	// check that our index is valid
	if (i < 0 || i >= size)
		std::cout << "Invalid position!" << std::endl;
	else {
		// If it is, store that index
		x = s[i];
	}
	return x;
}


// I guess this is the equivalent of peek without passing in an index?
int Stack1::stackTop() {
	// We want to know what's currently at the top of the stack.
	if (!isEmpty())
		return s[top];
	return -1;
}

bool Stack1::isEmpty() {
	// To know if the array is empty, we simply check if our top is -1
	return top == -1;
}

int Stack1::isFull() {
	// To check if our stack is full, we simply check if top is the same as our size - 1;
	return top == size - 1;
}