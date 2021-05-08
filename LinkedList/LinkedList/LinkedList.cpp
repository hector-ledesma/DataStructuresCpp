#include "LinkedList.h"

// THe array will be the data, n is size of array.
LinkedList::LinkedList(int A[], int n) {

	// We'll use these two to create all Nodes back to back.
	Node* next, * previous;

	head = new Node();
	head->data = A[0];
	

	// We'll create as many nodes as there are elems in the array.
	// Keeping track of the node we made and the one we're making now, we can continuously link them.
	//	Previous will hold the node that'll hold the new one, at first it will be the head
	//		Next = New node
	//		Previous node's next node is our new node aka next -> Next
	//			Then move our New node, to be the previous one before we loop again
	//			Previous = Previous.next
	//				etc.
	previous = head;
	for (int i = 1; i < n; i++) {
		next = new Node();
		next->data = A[i];
		previous->next = next;
		previous = next;
	}
}

LinkedList::~LinkedList() {
	delete head;
}

void LinkedList::Display() {
	Node *hold = head;

	while (hold != NULL) {
		std::cout << hold->data << " -> ";
		hold = hold->next;
	}
	std::cout<<std::endl;
}

// This method displays the list in reverse by traversing the list recursively and printing on return.

void LinkedList::RDisplay(Node* p) {
	
	if (p != NULL) {
		RDisplay(p->next);
		std::cout << p->data << " <- ";
	}
}

int LinkedList::count() {
	int count = 0;
	Node* current = head;
	while (current) {
		count++;
		current = current->next;
	}
	return count;
}