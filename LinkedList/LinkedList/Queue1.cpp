#include "Queue1.h"
#include <iostream>

using q = Queue1;

q::Queue1(int sz) {
	front = rear = -1;
	size = sz;
	Q = new int[sz];
}

void q::queue(int x) {
	// We want to move only the front index
	// first we check if it's full
	if (rear == size - 1)
		std::cout << "Queue full" << std::endl;
	else {
		rear++; // move forward first
		Q[rear] = x; // store at new index
	}
}

int q::dequeue() {
	int x = -1;

	if (front == rear)//check if our head hit our tail
		std::cout << "Queue is Empty" << std::endl;
	else {
		x = Q[front + 1];// We'll always point behind our actual target.
		front++;
	}

	return x;
}

void q::Display() {
	for (int i = front + 1; i <= rear; i++)
		std::cout << Q[i] << " ";
	std::cout << std::endl;
}