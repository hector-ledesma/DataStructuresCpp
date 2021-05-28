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
#include "HashTable.h"
#include "Graph.h"

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
	HashTable htable;
	htable.runChaining();

	Graph graph;
	graph.runGraphs();
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

/*
	QuickSort methods-------

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
//0 0 1
void Merge(int A[], int l, int mid, int h) {
	int i, j, k;
	i = l; j = mid + 1; k = l;
	int* B =new int[h + 1];

	while (i <= mid && j <= h) {
		if (A[i] < A[j]) B[k++] = A[i++];
		else B[k++] = A[j++];
	}
	while (i <= mid) B[k++] = A[i++];
	while (j <= h) B[k++] = A[j++];

	for (int i = l; i <= h; i++) A[i] = B[i];
	delete[]B;
}

void IMergeSort(int A[], int n) {
	// Index p will be the equivalent of recursive stack frames.
	//	the value of p basically represents how many elements are in the "arrays" we're comparing.
	//	So when p is 2, each one of our arrays will have two elements so -> index 0 and 1 are one array and index 2 and 3 are another array etc.
	int p, i, l, mid, h;
	for (p = 2; p <= n; p = p * 2) {// p will double til we go beyond the size of our passed in array.
		// Wow ok so, as I mentioned p will determine how many items per array.
		// So we'll use p to determine mid point and high point.
		// Index i moves by p + 1. So when p=2 it starts as i=0, then i=2, then i=4. This will determine starting point of this subarray.
		// Index l is = i
		// Index h is based on current i and current p. So say p=2 and i=4, h = 4 + 2 - 1 = 5. So our subarray will be 4->5 because p says we only have 2 items.
		//	If p were p=5. Then our subarray would be p=5, i=10 then h = 10+5-1 = 14 so -> 10->14. Five elements as per p.
		for (i = 0; i + p - 1 < n; i = i + p) {
			l = i;
			h = i + p - 1;
			mid = (l + h) / 2;
			Merge(A, l, mid, h); // Merge our subarray.
		}
	}
	if (p / 2 < n) Merge(A, 0, p / 2-1, n - 1); // If size of array is odd, we'll have one final lingering element that we'll want to merge into our array.

}

void MergeSort(int A[], int l, int h) {
	if (l < h) {
		int mid = (l + h) / 2;
		MergeSort(A, l, mid);
		MergeSort(A, mid + 1, h);
		Merge(A, l, mid, h);
	}
}

/*
	Count Sort consumes an obscene amount of memory lol. Stupid fast tho.

	O(n) time complexity always.
	Not adaptive as it doesn't matter whether it's sorted or not. There's no comparisons done other than for moving back the elements into the array.
	Since this version is creating brand new elements, it's hard to consider it stable. I'd say no.
	But the version presented by geekforgeeks that uses arithmetic seems to be stable as it preserves original order.
*/
int findMax(int A[], int n) {
	int largest = 0;
	for (int i = 0; i < n; i++)
		if (A[i] > largest) largest = A[i];

	return largest;
}

void CountSort(int A[], int n) {
	int max = findMax(A, n);	// Find the largest element in the array.
	int* c = new int[max + 1]{0}; // make a new array as large as the largest element we found and initialize it to 0.

	for (int i = 0; i < n; i++) c[A[i]]++; // Increase count at the value as index.

	int j = 0, k = 0;
	while (j < max + 1) {
		if (c[j] > 0) {
			A[k++] = j;
			c[j]--;
		}
		else {
			j++;
		}
	}
}

/*
	The idea behind radix sort is that we sort based on decimal value at nth position, where n represent the pass
		so pass 1 = 1s or (a[i]/1)%10
		pass 2 = 10s or (a[i]/10)%10
		pass 3 = 100s or (a[i]/100)%10
	And so on.
	We do as many passes as our largest value has digits.

	This sorting method will combine linked lists with arrays.

	It's technically O(n), but we can make a ton of n passes, but consumes way less space.
*/

class RNode { public: int value = 0; RNode* next = nullptr; }; // Node class we'll use for Radix Sort.
int Max(int A[], int n);
int countDigits(int x);
void initializeBins(RNode** p, int n);
int getBinIndex(int x, int idx);
void Insert(RNode** ptrBins, int value, int idx);
int Delete(RNode** ptrBins, int idx);
void RadixSort(int A[], int n) {
	int max = Max(A, n); // gotta find our largest value to know how many passes we need to perform
	int nPass = countDigits(max); // How many passes we'll have to perform before it's fully sorted.
	
	// Array of linked lists. "Bins"
	RNode** bins = new RNode * [10]{ nullptr }; // The size of the array is equals to the radix. So decimal = 10

	// We loop for as many passes as we need til we're done.
	for (int pass = 0; pass < nPass; pass++) {

		// For each pass, we need to handle all elements in the array.
		for (int i = 0; i < n; i++) {
			int binIdx = getBinIndex(A[i], pass); // We pass in our value, and which pass we're in, to get A[i]'s digit at plass'/nth place.
			Insert(bins, A[i], binIdx); // Now that we know where it belongs, insert it at this index's linked list.
		}
		
		// We now have to reposition our items based on how they're sorted at this pass.
		int i = 0; // Index i will let us access our bin. Since our bins is based on decimals, we only need to go from 0 to 9.
		int j = 0; // Index j will let us access our initial array in order.
		while (i < 10) {
			// Since any given index may contain multiple nodes, we loop until we've extracted all of them at this index i and placed them in our array.
			while (bins[i]) A[j++] = Delete(bins, i); // We extract as FIFO, we don't search.
			i++;
		}
		// I feel like, this shouldn't be needed if all our nodes are initialized with a nullptr for next as opposed to an uninitialized ptr.
		//initializeBins(bins, 10);
	}
	delete[]bins;
}

// This simply finds our largest value and returns it.
int Max(int A[], int n) {
	int max = INT16_MIN;
	for (int i = 0; i < n; i++)
		if (A[i] > max) max = A[i];
	return max;
}
// This method divides by 10 until we reach 0
int countDigits(int x) {
	int count = 0;
	while (x != 0) {
		x = x / 10;
		count++;
	}
	return count; // We return how many times we divided by 10. That lets us know how many digits we have in this number.
}

/*
	This is unneeded:
		1. When we first initialize the array, we can use of c++'s notation to set everything as nullptrs
		2. Since we're giving every node a default value of nullptr as opposed to an uninitialized pointer, when we're done deleting a list it'll always have nullptr as head.
*/
void initializeBins(RNode** p, int n) {
	for (int i = 0; i < n; i++) p[i] = nullptr;
}

int getBinIndex(int x, int idx) {
	// x is the value from the array so say 1923.
	// We increase 10 to the power of which pass we're in. So in pass 0, we get 1. But in pass 2, we get 100.
	// This basically reduces the number to the nth place. So 1923 is now 19, because we want to sort based on the hundredth place.
	// Mod it by 10, and it will give us the first digit so in this case, 9.
	return (int)(x / pow(10, idx)) % 10;
}

// Our "bins", or rather the array we're manipulating, will be an array of linked lists. Which are nothing but a root node pointing to other nodes.
// So RNode*[] is our array of pointers, RNode** is our pointer to our array of pointers.
void Insert(RNode** ptrBins, int value, int idx) {
	// Initialize our new node to be inserted
	RNode* temp = new RNode;
	temp->value = value;
	
	// If there's nothing at this index, then our new node will be the head of this list.
	if (ptrBins[idx] == nullptr) {
		ptrBins[idx] = temp;
	}
	else {
		RNode* p = ptrBins[idx]; // Extract the head.
		while (p->next) p = p->next; // Move until we find the last node.
		p->next = temp; // And link our new node at the end.
	}

}

// We extract values as FIFO. We don't search for any specific value.
int Delete(RNode** ptrBins, int idx) {
	RNode* p = ptrBins[idx]; // Extract head at index.
	ptrBins[idx] = ptrBins[idx]->next; // Move head to immediate child
	int x = p->value;
	delete p; // Delete extracted node.
	return x;
}

/*
	Bucket/Bin Sort is kind of a combo between count and Radix sort.
	
	It uses the idea of creating an array as large as our largest element so we got unique bins for each value.
	It uses linked lists to maintain the original order of the values.
*/
void Binsert(RNode** ptrBins, int idx);
void BinSort(int A[], int n) {
	int i, j;

	int max = findMax(A, n); // In this case, our max value itself will be the size of our auxiliary array.
	RNode** bins = new RNode*[max + 1]{ nullptr }; // Like with Radix sort, we need an array that holds linked lists. 

	for (i = 0; i < n; i++) Binsert(bins, A[i]); // Here we also simply extract the values of our initial array, and insert them into the list as nodes.
	// Main difference being that the value themselves will serve as the index of where to insert in the auxiliary array.

	// i for traversing auxiliary array.
	i = j = 0;
	// j for inserting back into our initial array.
	while (i < max + 1) {
		while (bins[i]) A[j++] = Delete(bins, i); // Once we find a linked list, extract it all one by one in a FIFO approach.
		i++;
	}
}

// This is the same as the Insert method for radix sort. Only difference is that we don't need a value parameter
// because our value doubles as our index
void Binsert(RNode** ptrBins, int value) {
	RNode* temp = new RNode;
	temp->value = value;

	if (!ptrBins[value]) {
		ptrBins[value] = temp;
	}
	else {
		RNode* p = ptrBins[value];
		while (p->next) p = p->next;
		p->next = temp;
	}
}

/*
	Shell Sort is just Insertion sort on steroids.
	It does passes for portions of the array based on a gap, until it gets down to a gap of 1 at which point it just does a normal insertion sort pass.
*/
void ShellSort(int A[], int n) {
	for (int gap = n / 2; gap >= 1; gap /= 2) { // We start with a gap of half the size of our array, and keep dividing by 2 until we get to 1.
		for (int j = gap; j < n; j+=gap) { // Inner loop will let us traverse the array by the gap.
			// We'll handle two items at a time.
			// temp will be the item at the current step of the gap.
			// i will be the tail we're initially comparing against
			// At first it will only be those two, but as we go deeper with j,
			//		our staring gap will cascade back to the first item in the following while loop.

			int temp = A[j]; // leading item to be moved back if necessary
			int i = j - gap; // Our base index which we'll use to traverse backwards if needed

			while (i >= 0 && A[i] > temp) { // We move back until all previous items are no longer larger than our temp value
				A[i + gap] = A[i]; // when we find a larger value, we move it forward.
				// So we found it at index i, we move it forward with i+gap. At first it will override our temp value but that's why we extracted it.
				i = i - gap; // We move our index back by reducing it by the gap amount until we either find the first value smaller or equals to our temp value or we exit the bounds.
			}

			A[i + gap] = temp; // Once we're out of the while loop, our index i will point directly behind the position we want to insert at
			//	so we move forward by adding back the gap and then inserting our temp value
		}
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
	// Merge
	int e[] = { 3,7,9,10,6,5,12,4,11,2 };
	std::cout << "Merge Sort:" << std::endl;
	IMergeSort(e, n);
	for (int i = 0; i < 10; i++) std::cout << e[i] << " | ";
	std::cout << std::endl;
	std::cout << std::endl;
	// Merge Recursive
	int f[] = { 4,8,10,11,7,6,13,5,12,3 };
	std::cout << "Merge Sort Recursively:" << std::endl;
	MergeSort(f, 0, n-1);
	for (int i = 0; i < 10; i++) std::cout << f[i] << " | ";
	std::cout << std::endl;
	std::cout << std::endl;
	// Count
	int g[] = { 3,7,9,10,6,5,12,4,11,2 };
	std::cout << "Merge Sort:" << std::endl;
	CountSort(g, n);
	for (int i = 0; i < 10; i++) std::cout << g[i] << " | ";
	std::cout << std::endl;
	std::cout << std::endl;
	// Radix
	int h[] = { 4,8,10,11,7,6,13,5,12,3 };
	std::cout << "Radix Sort:" << std::endl;
	RadixSort(h, n);
	for (int i = 0; i < 10; i++) std::cout << h[i] << " | ";
	std::cout << std::endl;
	std::cout << std::endl;
	// Bin/Bucket
	int k[] = { 3,7,9,10,6,5,12,4,11,2 };
	std::cout << "Bin/Bucket Sort:" << std::endl;
	BinSort(k, n);
	for (int i = 0; i < 10; i++) std::cout << k[i] << " | ";
	std::cout << std::endl;
	std::cout << std::endl;
	// Shell
	int l[] = { 4,8,10,11,7,6,13,5,12,3 };
	std::cout << "Shell Sort:" << std::endl;
	ShellSort(l, n);
	for (int i = 0; i < 10; i++) std::cout << l[i] << " | ";
	std::cout << std::endl;
	std::cout << std::endl;
}