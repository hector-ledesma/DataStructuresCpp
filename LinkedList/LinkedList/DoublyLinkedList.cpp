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
