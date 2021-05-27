#include "HashTable.h"
#include <iostream>

HNode::HNode(int val) {
	data = val;
}
HashTable::HashTable() {
	table = new HNode * [10]{ nullptr };
}

int HashTable::hashmod(int key) {
	return key % 10;
}

void HashTable::InsertChaining(int key) {
	int hidx = hashmod(key); // hashed index
	HNode* nuevo = new HNode(key); // Create our new node to be inserted.

	// If there's no head at this index, make new node the head
	if (!table[hidx]) table[hidx] = nuevo;
	else {
		HNode* lead = table[hidx]; // extract the head
		HNode* tail = table[hidx]; 

		// Traverse until we either find the end, with the lead
		//	or the data at the lead is the first value greater than our key
		while (lead && lead->data < key) {
			tail = lead; // move the tail to our lead
			lead = lead->next; // move our lead forward
		}
		
		// If our key is about to be our new head for an existing list
		if (tail == table[hidx]) {
			nuevo->next = tail; // make our new node point to previous head
			table[hidx] = nuevo; // make our new node the new head.
		}
		else {
			tail->next = nuevo;
			// we insert our new node right inbetween
			// head -> rest of list -> tail -> nuevo -> lead -> rest of list
			nuevo->next = lead;
		}
	}
}

int HashTable::SearchChaining(int key) {
	int hidx = hashmod(key); // hash our key
	HNode* p = table[hidx]; // Extract the head at this index

	while (p) {
		if (p->data == key) return p->data;
		p = p->next; // move forward if we haven't found our key
	}

	return -1; // if we exit the while loop it means we reached end of list before finding key so it's not there.
}

void printList(HNode* head) {
	while (head->next) {
		std::cout << head->data << " -> ";
		head = head->next;
	}
	std::cout << head->data;
}

void HashTable::runChaining() {
	int A[] = { 16,12,25,39,6,122,5,68,75, 115 }, n = 10;
	for (int i = 0; i < n; i++) InsertChaining(A[i]);

	// Print our list after being initialized
	for (int i = 0; i < n; i++) {
		std::cout << i << ".: ";
		if (table[i] != nullptr) {
			printList(table[i]);
		}
		std::cout << std::endl;
	}

	std::cout << "\n" << SearchChaining(68) << std::endl;
}

HashTable::~HashTable() {
	for (int i = 0; i < 10; i++) {
		HNode* p = table[i];
		while (table[i]) {
			table[i] = table[i]->next;
			delete p;
			p = table[i];
		}
	}
}