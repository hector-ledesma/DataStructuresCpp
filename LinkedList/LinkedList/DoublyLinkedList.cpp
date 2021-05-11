#include "DoublyLinkedList.h"
#include <iostream>

DoubleNode::DoubleNode() {
	previous = next = NULL;
	data = 0;
}
DoubleNode::DoubleNode(int data) {
	previous = next = NULL;
	this->data = data;
}

DoublyLinkedList::DoublyLinkedList() {
	head = NULL;
}
DoublyLinkedList::DoublyLinkedList(int A[], int sz) {
	// Create our new head node with the first element of the provided array.
	DoubleNode* current = new DoubleNode(A[0]);
	DoubleNode* newNode;
	head = current;
	// We'll use the size provided to traverse the array 
	for (int i = 1; i < sz; i++) {
		// Create a new node with the data at this index
		newNode = new DoubleNode(A[i]);
		// Assign previous to be our current.
		newNode->previous = current;
		// Make our current aim at our new node
		current->next = newNode;
		// Now move our current to our new node
		current = newNode;
	}
}