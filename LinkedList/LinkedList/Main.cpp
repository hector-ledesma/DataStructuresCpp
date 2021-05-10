// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"



int main()
{
	int A[] = { 1, 54, 12, 13, 7 };
	LinkedList list = LinkedList(A, 5);
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

	std::cout << "List is " << (list.isSorted() ? "sorted" : "unsorted") << std::endl;

	// Sorted Linked List
	std::cout << "\nUnsorted List ----" << std::endl;
	int B[] = {2,3,5,7,11};
	LinkedList sortedList = LinkedList(B, 5);


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

	std::cout << "List is " << (sortedList.isSorted() ? "sorted" : "unsorted") << std::endl;
}