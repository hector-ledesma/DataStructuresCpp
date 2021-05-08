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
}