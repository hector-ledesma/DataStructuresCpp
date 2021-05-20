#include "BinaryTree.h"
#include <iostream>
#include <queue>
#include <stack>

BinaryTree::BinaryTree() {
	root = NULL;
}

// I'll make my own constructor using a given array. 
// If I keep track of an index for given array, I can use a queue to assign children.
BinaryTree::BinaryTree(int* arr, int len) {
	std::queue<BTNode*> q;
	// We need to assign the head manually
	root = new BTNode();
	root->data = arr[0];
	// Push our root into the queue
	q.push(root);
	int i = 1; // This is the index we'll use to traverse the array, since we did index 0 manually, we start from 1

	while (!q.empty()) {
		// Step one is pop the node at the forefront of the queue
		BTNode* current = q.front(); q.pop();// Seems like extracting the value and popping are separate operations.
		
		// Steps 2 and 3 is to extract the next two values.
		if (i < len) { // Only enter this if there's any elements left.
			BTNode* l = new BTNode(); // Create a new node
			l->data = arr[i++]; // Assign it current data and index go up 1
			current->lchild = l; // assign it as child
			q.push(l); // push it to our queue.
			if (i < len) {
				BTNode* r = new BTNode();
				r->data = arr[i++];
				current->rchild = r; // assign it as child
				q.push(r); // push it to our queue.
			}
		}
		else {// if we're beyond the array, just assign null to children.
			current->lchild = current->rchild = NULL;
		}
	}
}

// This is a support function for constructing from a traversal
// It will search the passed in array (which will be a portion of the original in order array)
//		and return the index of the item we're searching for, or -1 if it's not in there.
int BinaryTree::searchInorder(int inArray[], int inStart, int inEnd, int data) {
	for (int i = inStart; i <= inEnd; i++) {
		if (inArray[i] == data) {
			return i;
		}
	}
	return -1;
}

// This constructor will use the resulting inorder and preorder traversals from another tree
//		and will create a brand new binary tree.
BTNode* BinaryTree::constructFromPost(int* inorder, int* preorder, int inStart, int inEnd) {
	static int prei = 0;
	// Much like with binary search, if our start is greater than our end
	//		it means we either went too far left (our end went too low)
	//		or we went too far right (our start went too high).
	// Which signifies there's no further children, so return nothing.
	if (inStart > inEnd)
		return nullptr;

	// Create our current parent
	BTNode* current = new BTNode();
	current->data = preorder[prei++];

	// This basically means we only have one node left in here, so return it.
	if (inStart == inEnd) {
		return current;
	}

	int splitIndex = searchInorder(inorder, inStart, inEnd, current->data); // We'll use this index to handle left and right children for any given nodes.
	current->lchild = constructFromPost(inorder, preorder, inStart, splitIndex - 1); // We want the next stack to only check from left up until the node right before this parent.
	current->rchild = constructFromPost(inorder, preorder, splitIndex + 1, inEnd); // We want the next stack to go from the node right after this parent to the end.

	return current;
}

// Preorder is root -> left -> right
void BinaryTree::Preorder(BTNode *current) {
	if (current) {
		std::cout << current->data << ", ";
		Preorder(current->lchild);
		Preorder(current->rchild);
	}
}

// Inorder is left -> root -> right
void BinaryTree::Inorder(BTNode* current) {
	if (current) {
		Inorder(current->lchild);
		std::cout << current->data << ", ";
		Inorder(current->rchild);
	}
}

// Postorder is left -> right -> root
void BinaryTree::Postorder(BTNode* current) {
	if (current) {
		Postorder(current->lchild);
		Postorder(current->rchild);
		std::cout << current->data << ", ";
	}
}

// Level order uses a queue in the exact same way I used it in my constructor
// Except now it goes from tree -> array instead of the other way around.
//
void BinaryTree::Levelorder() {
	std::queue<BTNode*> q;
	q.push(root);

	std::cout << root->data << ", ";
	while (!q.empty()) {
		// check if there are children. As we find the children, put them in the q and print em
		BTNode* current = q.front(); q.pop();
		if (current->lchild) {
			std::cout << current->lchild->data << ", ";
			q.push(current->lchild);
		}
		if (current->rchild) {
			std::cout << current->rchild->data << ", ";
			q.push(current->rchild);
		}
	}
}


// Iterative traversals
// For these, since we can't use the memory stack provided by recursion, we'll create our own stack. With blackjack and hookers.
void BinaryTree::PreorderIT() {
	std::stack<BTNode*> stk;
	BTNode* current = root;
	while (current || !stk.empty()) {
		if (current) {
			std::cout << current->data << ", ";// print current.
			stk.push(current); // push path to parent onto stack so we can come back up.
			current = current->lchild; // move to left child now that we know how to get back to parent.
		} // if current is null, we reached the end of this left side
		else {
			current = stk.top(); stk.pop();// So move back to our direct parent.
			current = current->rchild; // And then move down to our right child
		}
	}
	std::cout << std::endl;
}
// Same as preorder but print comes after we're done with left side.
// left -> root -> right
void BinaryTree::InorderIT() {
	std::stack<BTNode*> stk;
	BTNode* current = root;
	while (current || !stk.empty()) {
		if (current) {
			stk.push(current); // push path to parent onto stack so we can come back up.
			current = current->lchild; // move to left child now that we know how to get back to parent.
		} // if current is null, we reached the end of this left side
		else {
			current = stk.top(); stk.pop();// So move back to our direct parent.
			std::cout << current->data << ", ";// print after going back to our parent
			current = current->rchild; // And then move down to our right child
		}
	}
	std::cout << std::endl;
}

// Postorder is iffy
// The magic relies on backtracking:
//		We don't want to print root until we're done with both left and right side which means we have to go through the root onto the right side
//			and then know that we just finished with the right side.
//		We could check that the node we just backtracked from is the right child of this node. If it is then we can print and go back.
//		But this tells us that we'll only backtrack once, which means we can also store the pointer as a negative value to mark it as already visited left side.
void BinaryTree::PostorderIT() {
	std::stack<long int> stk; // We'll be storing memory addresses/pointers.
	BTNode* current = root;
	long int temp;
	while (current || !stk.empty()) {
		if (current) {
			stk.push((long int)current); // Store the current address.
			current = current->lchild; // move to left child
		}// We went too deep left, start moving right
		else {
			temp = stk.top(); stk.pop(); // Extract the memory address.
			if (temp > 0) {
				stk.push(-temp); // We mark this as visited by negating the address
				current = ((BTNode*)temp)->rchild; // Since we're still storing the right address in temp, dereference it to access its right child.
			} // If the address is negative, we've already visited this parent and therefore are done with the right side of it as well.
			// With some adjustments, we could also simply check if (current->rchild == previous) where previous = node we just backtracked from.
			else {
				std::cout << ((BTNode*)(-1 * temp))->data << ", "; // We want to negate the address to bring it back to its positive, and then dereference it to print.
				// As it's not only until we're done with both sides that we want to print
			}
		}
	}
	std::cout << std::endl;
}

int BinaryTree::height(BTNode* current) {
	int x = 0, y = 0;
	if (!current)
		return 0;
	x = height(current->lchild);
	y = height(current->rchild);
	if (x > y)
		return x + 1;
	else
		return y + 1;
}


int BinaryTree::count(BTNode* current) {
	if (current) 
		return count(current->lchild) + count(current->rchild) + 1;
	return 0;
}