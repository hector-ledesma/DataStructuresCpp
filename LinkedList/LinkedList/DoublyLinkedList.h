#pragma once
class DoubleNode {
public:
	DoubleNode* previous;
	int data;
	DoubleNode* next;

	DoubleNode();
	DoubleNode(int data);
};

class DoublyLinkedList {
public:
	DoubleNode* head;
};

