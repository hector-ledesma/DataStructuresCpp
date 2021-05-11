// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
#include "DoublyLinkedList.h"

int main()
{
	int A[] = { 1, 54, 12, 13, 7 };
	LinkedList list = LinkedList(A, 5, 1);
	list.Display();
	list.RDisplay(list.head);

	std::cout << "There are " << list.count() << " elements on this Linked List." << std::endl;
	std::cout << "Sum of all elements on list is: " << list.sum() << std::endl;
	std::cout << "Max element: " << list.max() << std::endl;

	std::cout << "\nUnsorted List ----" << std::endl;
	// Search for first element
	list.Search(1);
	list.Display();
	// Search for an element
	list.Search(13);
	list.Display();
	// Search for an element that's not there.
	list.Search(22);
	list.Display();

	// Insert at head
	list.Insert(21, 1);
	list.Display();
	// Inseert somewhere
	list.Insert(41, 3);
	list.Display();
	// Insert at the end
	list.Insert(9, 6);
	list.Display();
	// Insert out of bounds
	list.Insert(67, 12);
	list.Display();

	// Delete First
	list.Delete(1);
	// Delete in the middle 
	list.Delete(4);
	// Delete last
	list.Delete(7);
	list.Display();

	list.ReverseArr();
	list.Display();
	list.ReverseSP();
	list.Display();
	list.ReverseRec(NULL, list.head);
	list.Display();

	// Unsorted list to be appended
	int C[] = {3,2,12,97};
	LinkedList toAppend = LinkedList(C, 4, 2);
	list.Append(toAppend);
	list.Display();

	std::cout << "List is " << (list.isSorted() ? "sorted" : "unsorted") << std::endl;

	// Sorted Linked List
	std::cout << "\nUnsorted List ----" << std::endl;
	int B[] = {2,3,5,7,11};
	LinkedList sortedList(B, 5, 3);


	// Insert somewhere
	sortedList.InsertSorted(6);
	sortedList.InsertSorted(6);
	// Insert at head
	sortedList.InsertSorted(1);
	// Insert at end
	sortedList.InsertSorted(12);
	sortedList.InsertSorted(12);
	sortedList.InsertSorted(12);
	sortedList.DeleteDupes();
	sortedList.Display();

	// Sorted list to be append
	int D[] = {1,4,6,8,12};
	LinkedList toMerge(D, 5, 4);
	
	sortedList.Merge(toMerge);
	sortedList.Display();
	std::cout << "List is " << (sortedList.isSorted() ? "sorted" : "unsorted") << std::endl;
	std::cout << "List is " << (sortedList.isLoop() ? "a loop" : "not a loop") << std::endl;

	// Circular linked list
	int E[] = {3,8,9,12,24};
	LinkedList circularList(E, 5, 5);
	circularList.makeCircular();
	circularList.AppendCircular(25);
	circularList.InsertCircular(4, 1);
	circularList.InsertCircular(14, 5);
	circularList.DisplayCircular();
	circularList.DeleteCircular(4);
	circularList.DisplayCircular();
	std::cout << "List is " << (circularList.isLoop() ? "a loop" : "not a loop") << std::endl;

	int F[] = { 2,12,32,54,77 };
	DoublyLinkedList dubs(F, 5);
	std::cout << "Size: " << dubs.Length() << std::endl;
	dubs.Display();	
}