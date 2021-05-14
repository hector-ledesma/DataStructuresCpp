#include "Queue1.h"
#include <iostream>

using q = Queue1;

q::Queue1(int sz) {
	front = rear = 0;
	size = sz;
	Q = new int[sz];
}

// To make this circular, we'll use the power of modulo to move the rear pointer forward.
void q::queue(int x) {
	// We want to move only the front index
	// first we check if it's full
	if ((rear+1)%size == front)
		std::cout << "Queue full" << std::endl;
	else {
		rear = (rear+1)%size; // move forward first
		Q[rear] = x; // store at new index
	}
}

int q::dequeue() {
	int x = -1;

	if (front == rear)//check if our head hit our tail
		std::cout << "Queue is Empty" << std::endl;
	else {
		front = (front +1)%size;
		x = Q[front + 1];
	}

	return x;
}

void q::Display() {
	int i = front;
	do {
		std::cout << Q[i] << " ";
		i = (i + 1) % size;
	} while (i != (rear + 1)%size);
	std::cout << std::endl;
}