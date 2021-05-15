#include "Queue2.h"
#include <iostream>

using q = Queue2;

q::Queue2() {
	head = tail = NULL;
}

void q::queue(int x) {
	Node* t = new Node(x);
	// If null didn't get created, heap is full
	if (!t)
		std::cout << "Queue is Full\n";
	else {
		if (!head)
			head = tail = t;
		else {
			tail->next = t;
			tail = t;
		}
	}
}

int q::dequeue() {
	int x = -1;
	
	if (!head)
		std::cout << "Queue is Empty\n";
	else {
		x = head->data;
		Node* hold = head;
		head = head->next;
		delete hold;
	}

	return x;
}

void q::Display() {
	Node* current = head;
	while (current) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout<<std::endl;
}