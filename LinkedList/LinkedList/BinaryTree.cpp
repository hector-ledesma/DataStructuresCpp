#include "BinaryTree.h"
#include <iostream>

using q = BTQueue;

q::BTQueue() {
	head = tail = NULL;
}

void q::queue(BTNode x) {
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

BTNode* q::dequeue() {
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

void q::Display() {
	BTNode* current = head;
	while (current) {
		std::cout << current->data << " ";
		current = current->rchild;
	}
	std::cout << std::endl;
}