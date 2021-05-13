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

int Stack1::stackTop() {
	// We want to know
}

bool Stack1::isEmpty() {

}

int Stack1::isFull() {

}