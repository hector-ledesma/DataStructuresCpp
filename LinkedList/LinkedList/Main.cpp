// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "Stack1.h"
#include "Stack2.h"
#include "Queue1.h"
#include "Queue2.h"
#include "BinaryTree.h"
#include "AVL.h"

void sortingCode();

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
	std::cout<< " Found " << sortedList.findMiddle() << std::endl;

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

	// Doubly linked list
	int F[] = { 2,12,32,54,77 };
	DoublyLinkedList dubs(F, 5);
	std::cout << "Size: " << dubs.Length() << std::endl;
	dubs.Insert(13, 2);
	std::cout << "Deleting " << dubs.Delete(3) << std::endl;
	dubs.Display();	
	dubs.Reverse();
	dubs.Display();

	// Stack operations
	/*	Updated this stack to char instead of int for the sake of building the infix to postfix conversion methods.
	Stack1 s1(5);
	std::cout << (s1.isEmpty() ? "It's empty" : "It's not empty") << std::endl;
	std::cout << (s1.isFull() ? "It's full" : "It's not full") << std::endl;
	s1.pop();
	s1.push(2);
	s1.push(21);
	s1.push(56);
	s1.push(7);
	s1.push(9);
	s1.Display();
	std::cout << (s1.isEmpty() ? "It's empty" : "It's not empty") << std::endl;
	std::cout << (s1.isFull() ? "It's full" : "It's not full") << std::endl;
	s1.push(777);

	std::cout << "Peeking at index 1: " << s1.peek(1) << std::endl;
	std::cout << "Peeking at index 2: " << s1.peek(2) << std::endl;
	std::cout << "Peeking at index 3: " << s1.peek(3) << std::endl;
	*/

	std::cout << "\nStack Operations----" << std::endl;
	Stack2 s2 = Stack2();
	s2.push(3);
	s2.push(31);
	s2.push(12);
	s2.push(93);
	s2.push(148);
	s2.push(74);
	s2.push(58);
	s2.push(64);
	s2.push(16);
	s2.Display();

	// In to post testing
	std::cout << "\nInfix to Postfix----" << std::endl;
	Stack1 intopost = Stack1(16);
	const char *infix = "((2+5)*6)-7+8-1";
	char* post = intopost.InToPost(infix);
	int eval = intopost.eval(post);
	std::cout << post << std::endl;
	std::cout << eval << std::endl;


	// Queue operations
	std::cout << "\nQueue Operations----" << std::endl;
	Queue1 q1 = Queue1(5);
	q1.queue(2);
	q1.queue(4);
	q1.queue(12);
	q1.queue(89);
	q1.queue(39);
	q1.queue(39);
	q1.dequeue();
	q1.dequeue();
	q1.dequeue();
	q1.queue(9);
	q1.queue(14);
	q1.queue(3);
	q1.queue(91);
	q1.Display();


	Queue2 q2 = Queue2();
	q2.queue(9);
	q2.queue(34);
	q2.queue(95);
	q2.queue(912);
	q2.queue(51);
	q2.queue(18);
	q2.queue(76);
	q2.queue(81);
	q2.queue(8);
	q2.queue(34);
	q2.queue(46);

	q2.Display();
	for (int i = 0; i < 11; i++)
		std::cout << "Dequeued " << q2.dequeue() << std::endl;
	q2.dequeue();
	std::cout << std::endl;

	// BinaryTree stuff
	int ar[] = {1,2,3,4,5,6,7};
	BinaryTree tree = BinaryTree(ar, 7);

	// Iteratively
	std::cout << "Preorder Iteratively:" << std::endl;
	tree.PreorderIT();

	std::cout << "Inorder Iteratively:" << std::endl;
	tree.InorderIT();

	std::cout << "Postorder Iteratively:" << std::endl;
	tree.PostorderIT();

	std::cout << "Level Order:" << std::endl;
	tree.Levelorder();
	std::cout << std::endl;
	std::cout << std::endl;
	// Recursively
	std::cout << "Preorder Recursive:" << std::endl;
	tree.Preorder(tree.root);
	std::cout << std::endl;

	std::cout << "Inorder Recursive:" << std::endl;
	tree.Inorder(tree.root);
	std::cout << std::endl;

	std::cout << "Postorder Recursive:" << std::endl;
	tree.Postorder(tree.root);
	std::cout << std::endl;
	
	std::cout << "Node Count:" << std::endl;
	std::cout << tree.count(tree.root) << std::endl;

	std::cout << "Tree Height:" << std::endl;
	std::cout << tree.height(tree.root) << std::endl;

	std::cout << "AVL Tree: -------" << std::endl;
	AVL avl = AVL();
	avl.root = avl.RInsert(avl.root, 20);
	avl.RInsert(avl.root, 10);
	avl.RInsert(avl.root, 30);
	avl.RInsert(avl.root, 31);
	avl.RInsert(avl.root, 25);
	avl.RInsert(avl.root, 26);
	avl.Delete(avl.root, 10);
	avl.Delete(avl.root, 20);
	std::cout << "---------" << std::endl;

	sortingCode();
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
	- Min time (no swaps/already sorted) = O(n)
	- Max time = O(n^2)

	No. of passes = (n-1)passes
	No. of comparisons = O(n^2)
	Max No. of Swaps = O(n^2)
	It is adaptive because it can take advantage of existing order in input by using a FLAG.
	It is stable because it retains original order when values are equal, because swaps only happen when a value is greater.

	Due to the nature of BubbleSort, each nth pass will be indicative of the nth largest element.
	So you can use this to "Sort" an array n times, and the nth element from the end will be the nth largest element.
*/
void BubbleSort(int A[], int n) {
	// Gotta exit early if array already sorted. To do so, we'll use a flag
	bool flag = false;
	// We want to do this for each element in the array.
	for (int i = 0; i < n - 1; i++) {
		flag = false;
		// And for each element, compare it to every other element
		//	that hasn't been compared.
		for (int j = 0; j < n - 1 - i; j++) {
			if (A[j] > A[j + 1]) {
				swap(&A[j], &A[j + 1]);
				flag = true; // Flip flag to true if we make a swap
			}
		}
		if (!flag) break; // If we didn't perform any swaps in this pass, array is already sorted.
	}
}

/*
	Bubble and Insertion sort have very similar statistics.
	Same min time, same max time.
	Where they differ, is in their unique usefulness.

	Bubble sort lets you quickly find the kth largest element in an array.
	Whilst Insertion sort lets you easily handle Linked lists.

	These are the only two algorithms that are adaptive, which take advantage of already sorted arrays.
	These are also 2 out of the only 3 algorithms that are stable, respecting original order for duplicates.
*/

/*
	Min time = O(n)
	Max time = O(n^2)

	No. of passes = (n-1)passes
	No. of comparisons = O(n^2)
	Max No. of Swaps = O(n^2)

	With a linked list, Insertion sort doesn't require any element shifting, just rearranging of pointers.
	Therefore Insertion sort is more compatible/useful with linked lists than arrays. It is designed for Lists.

	It is Adaptive, as we don't cascade comparisons unless our elements fit the condition. So if it's sorted, we don't do extra work.
	It is Stable, the duplicate will not be shifted as it is not greater. So original order is retained.
*/
void InsertionSort(int A[], int n) {
	// n-1 passes, but instead of 0 to n-1 it's 1 to n
	for (int i = 0; i < n; i++) {
		int j = i - 1; // Index J will start at one prior to index i.
		// Index i = item we want to insert
		// Index j = last/largest element in "sorted" portion of our array.
		// i will move right
		// j will move left
		int x = A[i]; // Extract our value.
		while (j > -1 && A[j] > x) { // Loop for as long as j is within bounds, and our elements from sorted portion of the array are larger than our item to be inserted.
			A[j + 1] = A[j]; // If our item is larger, shift the largest element right by one.
			j--; // Move our index to a smaller element in sorted portion.
		}
		// Once we're out of the loop, it means we're directly behind the index where our item to be inserted belongs.
		A[j + 1] = x; // so insert it directly in front.
	}
}

/*

	No. of comparisons = O(n^2)
	No. of Swaps = O(n) Only algorithm with minimal number of swaps.

	Just like bubble sort gives us kth largest element for k passes;
	Selection sort is great to find kth smallest element after k passes.

	Not adaptive. Can't judge whether or not the rest of the array is sorted simply because our current index is in the right spot.
	Not stable. Whichever duplicate comes first, will be placed at the right index first.
*/
void SelectionSort(int A[], int n) {
	for (int i = 0; i < n - 1; i++) { // Each value of i will mark what's the current smallest element we're trying to find.
		int j,k; // This index will point to the final smallest index we find.
		// Starting at i for both j and k means we don't need to compare the already sorted portions.
		for (k = j = i ; j < n; j++) {// j will go through each element in the unsorted portion of the array.
			if (A[j] < A[k]) k = j; // If item at index j is smaller (what we want), then move k to j.
		}
		swap(&A[i], &A[k]); // Once we're done checking all of the unsorted elements, move the item we found at index k, to our index i where it belongs.
	}
}

//QuickSort methods

/*
	Best Case -> If partitioning is always in the middle = O(nlogn)
	Worst case -> If partitioning is at the end of the list (if it's already sorted) = O(n^2)
	Average Runtime = O(nlogn)

	Also called Partition Exchange Sort and Selection Exchange Sort.

	A clear distinction between Quick sort and Selection Sort:
		With selection sort, you select a POSITION and find the element that belongs there.
		With quick sort, you select an ELEMENT and find the position where it belongs.
*/
int Partition(int A[], int l, int h) {
	int pivot = A[l]; // The passed in l index will represent our pivot.
	int i = l+1, j = h; // The passed in h index will represent the size of our array initially, but then it will become the last index we want to check as we recursively dig.

	// We want to do this at least once, so that i moves up and j moves down at least once.
	do {
		while (i <= j && A[i] <= pivot) // Index i will move forward and look for the first element that's larger or equals to our pivot
		{
			i++;
		 }
		while (j >= i && A[j] > pivot) // Index j will move back and look for the first element smaller than our pivot
		{
			j--;
		}
		if (i < j) swap(&A[i], &A[j]); // If j is still in front of i, then we've found two items we want to swap, so swap em.
		// Effectively moving elements smaller than our pivot to the left of the array, and larger elements to the right.
	} while (i < j); // Once j ends up behind i, we've finished swapping based on our pivot.

	swap(&A[l], &A[j]); // If we've exited the loop, that means j is less than i, therefore all elements are reposition based on pivot.
	// So move our pivot to the index j has found for us, and move the item and index j to where our pivot is placed.
	return j; // Return the position we moved our pivot to. This will serve as our "h" index/last element to check for lower recursive levels.
}

void QuickSort(int A[], int l, int h) {
	if (l < h) {
		int p = Partition(A, l, h);
		QuickSort(A, l, p-1);
		QuickSort(A, p+1, h);
	}
}

void sortingCode() {
	std::cout << "Sorting business: ------" << std::endl;
	std::cout << std::endl;
	// Bubble
	int a[] = { 3,7,9,10,6,5,12,4,11,2 }, n = 10;
	std::cout << "Bubble Sort:" << std::endl;
	BubbleSort(a, n);
	for (int i = 0; i < 10; i++) std::cout << a[i] << " | ";
	std::cout << std::endl;
	std::cout << std::endl;
	// Insertion
	int b[] = { 4,8,10,11,7,6,13,5,12,3 };
	std::cout << "Insertion Sort:" << std::endl;
	InsertionSort(b, n);
	for (int i = 0; i < 10; i++) std::cout << b[i] << " | ";
	std::cout << std::endl;
	std::cout << std::endl;
	// Selection
	int c[] = { 3,7,9,10,6,5,12,4,11,2 };
	std::cout << "Selection Sort:" << std::endl;
	InsertionSort(c, n);
	for (int i = 0; i < 10; i++) std::cout << c[i] << " | ";
	std::cout << std::endl;
	std::cout << std::endl;
	// Quick
	int d[] = { 4,8,10,11,7,6,13,5,12,3 };
	std::cout << "Quick Sort:" << std::endl;
	QuickSort(d, 0, n-1);
	for (int i = 0; i < 10; i++) std::cout << d[i] << " | ";
	std::cout << std::endl;
	std::cout << std::endl;
}