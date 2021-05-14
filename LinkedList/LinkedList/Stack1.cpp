#include "Stack1.h"
#include <iostream>

Stack1::Stack1(int sz) {
	top = -1;
	size = sz;
	s = new char[sz];
}

void Stack1::Display() {
	for (int i = top; i >= 0; i--)
		std::cout << s[i] << " ";
	std::cout << std::endl;
}
void Stack1::push(char x) {
	// Firs we want to check that the stack isn't full
	if (isFull())
		std::cout << "Stack overflow" << std::endl;
	else {
		top++;
		s[top] = x;
	}
}

char Stack1::pop() {
	char x = -1;

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
char Stack1::peek(int index) {
	// Calculate our index
	int i = top - index + 1;
	char x = -1;
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
char Stack1::stackTop() {
	// We want to know what's currently at the top of the stack.
	if (!isEmpty())
		return s[top];
	return -1;
}

bool Stack1::isEmpty() {
	// To know if the array is empty, we simply check if our top is -1
	return top == -1;
}

bool Stack1::isFull() {
	// To check if our stack is full, we simply check if top is the same as our size - 1;
	return top == size - 1;
}

// This method will return true only if the passed in char is an operand.
bool Stack1::isOperand(char x) {
	return !(x == '+' || x == '-' || x == '*' || x == '/');
}

// This method will give us the power level of the passed in operators
int Stack1::pre(char x) {
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	return 0;
}

char* Stack1::InToPost(const char* in) {
	// Indices for traversing
	int i = 0, j = 0;
	// Postfix string needs to be as big as our infix string
	char* post = new char[size];

	// We want to traverse until we hit the end of the infix string
	while (in[i] != '\0') {
		// First we check if we're dealing with an operand
		if (isOperand(in[i]))
			post[j++] = in[i++]; // If we are, move our current operand into postfix and move up an index for both indices
		else { // If it's an operator proceed
			// First we want to know if our current operator is larger than our stored operator
			// Also if our our stack is empty
			if (isEmpty() || pre(in[i]) > pre(stackTop()))
				push(in[i++]);	// Then we move our current operator into the stack
			// Else, if it's either smaller or equal preposition, move the item at the top of the stack into post, but don't move up index
			else
				post[j++] = pop();	// This way, when we loop back around we will compare the same operator to whatever is currently at the top of the stack
									// Until we either empty the stack, or find an operator with smaller pre
		}
	}

	// Once we're done with infix, check that our stack is empty, if it isn't move the operators into post
	while (!isEmpty())
		post[j++] = pop();

	// Once we're done with all that, add string endy thingy
	post[j] = '\0';

	return post;
}
