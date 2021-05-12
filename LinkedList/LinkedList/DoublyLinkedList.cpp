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

// This is basically the exact same as a normal list.
void DoublyLinkedList::Display() {
	DoubleNode* current = head;
	while (current) {
		std::cout << current->data << " <->";
		current = current->next;
	}
	std::cout << std::endl;
}

int DoublyLinkedList::Length() {
	int len = 0;
	DoubleNode* current = head;
	while (current) {
		len++;
		current = current->next;
	}
	return len;
}

void DoublyLinkedList::Insert(int data, int index) {
	DoubleNode* current = head;
	DoubleNode* newNode = new DoubleNode(data);
	// First we must check if we're trying to insert at head
	if (index == 0) {
		// If head is null, we simply make thi snew head
		if (!head) {
			head = newNode;
		}
		// Else modify the links and make it our new head
		else {
			// Node's next will be current head
			newNode->next = head;
			// make head point back to new node
			head->previous = newNode;
			// Make head new node
			head = newNode;
		}
	}
	// If we don't wanna insert at head, we move til we get to index.
	else {
		// We want to stop until we're one index before our target, or we hit the end of the list.
		for (int i = 0; i < index - 1 && current->next; i++) current = current->next;

		// Once we've reached our target, we make sure there's an element at the targer index
		// if there is, make its previous point to our new node
		if (current->next) current->next->previous = current;
		// If there's no next node, we simply don't worry about making a backfacing connection.
		// Make our current point towards the node after our current/potentially NULL
		newNode->next = current->next;
		// new node should also connect back to our current index
		newNode->previous = current;
		// Our new node now faces towards the node after current, and back to our current.
		// All that's left, is to move our current to face to our new node instead of th eone after the new node
		current->next = newNode;
	}
}

// Standard link delete
// Standard assumptions:there's elements in the list
int DoublyLinkedList::Delete(int index) {
	DoubleNode* current = head;
	int x = -1;
	// First check it's the head
	if (index == 1) {
		head = head->next;
		x = current->data;
		delete current;
		if (head)
			head->previous = NULL;
	}
	else {
		// Traverse til our target node
		for (int i = 0; i < index - 1; i++) current = current->next;
		
		// Link the node behind our target to the node after
		current->previous->next = current->next;
		// If there's a node after, create the backfacing link
		if (current->next)
			current->next->previous = current->previous;

		x = current->data;
		delete current;

	}

	return x;
}
