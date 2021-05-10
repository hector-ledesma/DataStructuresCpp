#include "LinkedList.h"

Node::Node(int n) {
	data = n;
}

Node::Node() {}

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

int LinkedList::sum() {
	int s = 0;
	Node* current = head;
	while (current) {
		s += current->data;
		current = current->next;
	}
	return s;
}

int LinkedList::max() {
	int m = INT16_MIN;
	Node* current = head;

	while (current) {
		if (current->data > m)
			m = current->data;
		current = current->next;
	}

	return m;
}

// This linear seach method assumes that order doesn't matter, and it will move to head
//		any searched node, so next time it takes less time to find.
Node* LinkedList::Search(int key) {
	// For as long as our node is not null, keep looking.
	Node* current = head;
	Node* prev = NULL;
	while (current != NULL) {
		if (key == current->data) {
			// If our find is the head, simply return it
			// doing any other steps would error out, since our previous node would be NULL
			if (current == head)
				return current;
			// Else, we want to move current node to the head.
			// 1.) Move the next node to be previous' next
			prev->next = current->next;
			// 2.) Make current point to current head
			current->next = head;
			// 3.) Make current the head
			head = current;
			// And just return our node.
			return current;
		}
		// We want to keep track of both the next node, and the one we just visited.
		prev = current;
		current = current->next;
	}
	// If we make it out of the loop, we didn't find anything.
	return NULL;
}

void LinkedList::Insert(int data, int pos) {
	Node* n = new Node(data);
	Node* current = head;
	// We want to loop until we either
	//	1- Hit our index or
	//	2- We hit the end of the list
	// If index is 0 return the head:
	if (pos == 0) {
		n->next = head->next;
		head = n;
		return;
	}

	for (int i = 0; i < pos - 1 && current->next != NULL; i++)
		current = current->next;

	// Once we have found the node where we'll insert our new node:
	// Make our new node point to the node that's already there.
	n->next = current->next;
	// Make our current node, point at our new one now.
	current->next = n;
}

// This method assumes we're using a sorted Linked List
void LinkedList::InsertSorted(int data) {
	Node* n = new Node(data);
	// If there's no head (brand new list), then simply insert this in the head.
	if (!head) {
		head = n;
		return;
	}

	Node* current = head;
	Node* prev = current;

	// We want to loop until our current is NULL, or it's greater thanour target.
	while (current && current->data < data) {
		prev = current;
		current = current->next;
	}

	// Check if we're targetting the head.
	if (current == head) {
		n->next = head;
		head = n;
		return;
	}

	// Once we've found our position:
	// The node occupying this position becomes our new node's next.
	n->next = prev->next;
	// Assign our node to this position through prev's next
	prev->next = n;
}

int LinkedList::Delete(int pos) {
	Node* current, *prev;
	// If we don't find anything, we return -1
	int found = -1;

	// Check if it's the head
	if (pos == 1) {
		// Data to be returned
		found = head->data;
		// Store the pointer so we can delete it
		prev = head;
		// Make the second Node the head
		head = head->next;
		// Delete our stored node
		delete prev;
		return found;
	}

	// If it's not the head, business as usual.
	current = head;
	prev = NULL;
	// Same as searching/inserting at an index.
	// Traverse til we either hit the end, or we find our target.
	for (int i = 0; i < pos - 1 && current; i++) {
		prev = current;
		current = current->next;
	}

	// If we found nothing, it will be NULL.
	if (!current)
		return found;

	// If it isn't null, then continue
	prev->next = current->next;
	found = current->data;
	delete current;

	return found;
}

bool LinkedList::isSorted() {
	// We check all nodes and compare them to the previous one,
	//	we find a value smaller than the previous, we exit early
	int smallest = INT_MIN;
	Node* current = head;

	while (current) {
		// Check if data is smaller, if so exit early
		if (current->data < smallest)
			return false;
		// Otherwise, store this value
		smallest = current->data;
		// And move up
		current = current->next;
	}


	return true;
}
