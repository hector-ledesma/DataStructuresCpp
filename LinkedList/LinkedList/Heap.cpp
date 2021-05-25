#include "Heap.h"
#include <iostream>
#include <vector>

void Heap::swap(std::vector<int>& a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void Heap::CreateHeap(std::vector<int>& vex, int A[], int n) {
	for (int i = 0; i < n; i++) {
		Insert(vex, A[i]);
	}
}
void Heap::Insert(std::vector<int>& a, int key) {
	auto i = a.size();
	a.emplace_back(key); // Add new element to the back of our array/vector

	// Rearrange/heaphify our array.
	// We'll loop until we either reach the end of the array ( i <= 0 )
	//		or the upcoming parent isn't smaller so we don't need to shift.
	while (i > 0 && key > a[(i - 1) / 2]) {
		a[i] = a[(i-1)/2]; // Move the parent back to this index.
		i = (i - 1) / 2; // Move up our index to the parent's index.
	}
	// Once we're out of the loop, our index will point to where we need to insert our key.
	a[i] = key; // So insert it.
}
void Heap::InsertInPlace(std::vector<int>& a, int n) {
	auto i = a.size();
	int temp = a[i-1];
	while (i > 0 && temp > a[(i-1)/2]){
		a[i] = a[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	a[i] = temp;
	}
int Heap::Delete(std::vector<int>& a, int n) {
	int x = a[0]; // Max element to be deleted.
	a[0] = a[n - 1]; // Replace max element to be deleted with last element, and start bubbling it down.

	int i = 0; // This points to our current node we wanna buble down.
	int j = 2*i + 1; // and to its first child

	while (j < n - 1) {
		// Compare left and right children
		if (a[j] < a[j + 1]) // If left is smaller, we stay pointing at left/first child.
			j++; // If right child is larger, point at it by increasing index by one.

		if (a[i] < a[j]) { // If our child node is larger
			swap(a, i , j); // Swap it with our child node
			i = j; // and move our parent node index to where we just moved it.
			j = 2 * i + 1; // Find the first child of this node we just moved to.
		}
		else { // If our parent node is already larger than the largest child, then we've found the place for our parent node.
			break;
		}
	}
	a.pop_back();
	return x; // Return our max node we've just deleted..
	}