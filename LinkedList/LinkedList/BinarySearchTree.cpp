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

// Simple iterative BST Search
Node* BST::Search(int key) {
    Node* t = root;
    // If we exit it's cause we hit null.
    while (t) {
        if (key == t->data)
            return t; // Found
        else if (key < t->data)
            t=t->lchild; // Key is smaller so we go left
        else
            t=t->rchild; // Key is larger so we go right
    }
    return nullptr;
}

// Recursive methods

Node* BST::RInsert(Node *p, int key) {

    if (!p) {
        Node* child = new Node(key);
        return child;
    }
    else if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);

    return p;
}

// Support methods for Delete
int BST::Height(BSTNode* p) {
    if (!p) return 0;
    int x = Height(p->lchild);
    int y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

BSTNode* BST::InPre(BSTNode *p) {
    while (p && p->rchild)
        p=p->rchild;
    return p;
}

BSTNode* BST::InSucc(BSTNode *p) {
    while (p && p->lchild)
        p=p->lchild;
    return p;
}

Node* BST::Delete(BSTNode *p, int key) {
    if (!p)
        return NULL;
    if (!p->lchild && !p->rchild) {
        if (p == root)
            root = NULL;
            delete p;
        return NULL;
    }

    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
    else {
        BSTNode *q;
        if (Height(p->lchild) > Height(p->rchild)) {
            q=InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q=InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}
