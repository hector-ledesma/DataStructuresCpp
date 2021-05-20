//
//  BinarySearchTree.cpp
//  DataStructuresCpp
//
//  Created by Karen Rodriguez on 5/20/21.
//

#include "BinarySearchTree.h"
using Node = BSTNode;
void BST::Insert(int key) {
    Node* r;
    Node* t = r = root;
    Node *p;

    // This triggers if we don't have a root in our BST
    // simply creates a new node and assigns it to root
    if (!root) {
        p = new Node(key);
        root = p;
        return;
    }

    // Go deep until we hit the end of our tree or our target
    while (t) {
        r=t;    // Move our tail pointer to our lead pointers.
        if (key < t->data)  // If our key is lower than our current head
            t = t->lchild;  // Go left
        else if (key > t->data) // Else if it's greater we go right
            t = t->rchild;
        else
            return; // We don't accept dupes, so in this case do nothing.
    }

    // Once t is null, we've hit our target, as r will be pointing to
    // what will be the parent of this new node.
    p=new Node(key); // make our new node
    // Check where it belongs
    if (key < r->data)  // If papa's data is bigger,
        r->lchild = p;  // child is left/smaller
    else    // We don't check for == case, as we handled that in our initial search.
        r->rchild = p;
}
