#include "Stack2.h"
#include <iostream>
#include "LinkedList.h"

void Stack2::push(int x) {
	Node* newNode = new Node;
	// If the new node wasn't allocated into memory, that means there's no more space for creating new nodes.
	if (!newNode) {
		std::cout << "Heap is full." << std::endl;
		return;
	}
	// insert our data into the node
	newNode->data = x;
	// If we get our new node, we want to inseart at the head.
	// So step one is point our new node to current head
	newNode->next = head;
	// Make our new node our new head
	head = newNode;
	// count++ if we were keepiung track
}

int Stack2::pop() {
	int x = -1;
	// If we have nothing at the head
	if (!head)
		return x;
	// Else, first we extract the node
	Node* hold = head;
	// extract the data
	x = hold->data;
	// Then move the head
	head = head->next;
	// then delete our held node
	delete hold;
	// return data
	return x;
}

void Stack2::Display() {
	Node* current = head;

	while (current) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}