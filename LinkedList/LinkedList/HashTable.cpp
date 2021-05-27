#include "HashTable.h"
#include <iostream>

HNode::HNode(int val) {
	data = val;
}
HashTable::HashTable() {
	table = new HNode * [10]{ nullptr };
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

/*
	With linear probing, lambda/loading factor has to always be less than or equals to 5.
	Meaning, the table array has to always be half empty at the very least.

	We know if a search fails once we find empty space.

	Deleting is always discouraged when using Linear Probing. This is because when deleting,
	you'll have to rehash all your keys.
	
	So you're better off using a flag with your nodes to indicate whether they've been "Deleted" or not.
*/
int HashTable::hashprob(int key) {
	return key % size;
}
void HashTable::InsertProbe(int H[], int key) {
	int idx = hashprob(key);
	// With Linear probe, we're not using linked lists, so we have to find a different spot to insert at.
	if (H[idx] != 0) idx = LinearProbe(H, key);
	H[idx] = key;
}
int HashTable::SearchProbe(int H[], int key) {
	int idx = hashprob(key);
	int i = 0;
	while (H[(idx + 1) % size] != key) {
		i++;
		if (H[(idx + i) % size] == 0) return -1; // failure condition is if we go around the whole array.
	}
	return (idx + i) % size;
}
int HashTable::LinearProbe(int H[], int key) {
	int idx = hashprob(key);
	int i = 0;
	while (H[(idx + i) % size] != 0) i++; // We basically just keep rehashing til we find an empty spot by adding 1 to i
	return (idx + i) % size; // return index for first empty spot.
}