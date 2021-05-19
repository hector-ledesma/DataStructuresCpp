#include "BinaryTree.h"
#include <iostream>
#include <queue>

using q = BTQueue;

BTQueue::BTQueue() {
	head = tail = NULL;
}

void BTQueue::queue(BTNode x) {
	BTNode* t = new BTNode(x);
	// If null didn't get created, heap is full
	if (!t)
		std::cout << "Queue is Full\n";
	else {
		if (!head)
			head = tail = t;
		else {
			tail->rchild = t;
			tail = t;
		}
	}
}

BTNode* BTQueue::dequeue() {
	BTNode* x = NULL;

	if (!head)
		std::cout << "Queue is Empty\n";
	else {
		x = head;
		BTNode* hold = head;
		head = head->rchild;
		delete hold;
	}

	return x;
}

void BTQueue::Display() {
	BTNode* current = head;
	while (current) {
		std::cout << current->data << " ";
		current = current->rchild;
	}
	std::cout << std::endl;
}

BinaryTree::BinaryTree() {
	root = NULL;
}

// I'll make my own constructor using a given array. 
// If I keep track of an index for given array, I can use a queue to assign children.
BinaryTree::BinaryTree(int* arr, int len) {
	std::queue<BTNode*> q;
	// We need to assign the head manually
	root = new BTNode();
	root->data = arr[0];
	// Push our root into the queue
	q.push(root);
	int i = 1; // This is the index we'll use to traverse the array, since we did index 0 manually, we start from 1

	while (!q.empty()) {
		// Step one is pop the node at the forefront of the queue
		BTNode* current = q.front(); q.pop();// Seems like extracting the value and popping are separate operations.
		
		// Steps 2 and 3 is to extract the next two values.
		if (i < len) { // Only enter this if there's any elements left.
			BTNode* l = new BTNode(); // Create a new node
			l->data = arr[i++]; // Assign it current data and index go up 1
			q.push(l); // push it to our queue.
			if (i < len) {
				BTNode* r = new BTNode();
				r->data = arr[i++];
				q.push(r); // push it to our queue.
			}
		}
		else {// if we're beyond the array, just assign null to children.
			current->lchild = current->rchild = NULL;
		}
	}
}