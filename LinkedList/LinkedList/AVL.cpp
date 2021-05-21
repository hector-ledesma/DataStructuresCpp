#include "AVL.h"
#include <iostream>

int NodeHeight(AVNode* p) {
    int hl, hr;
    // Check that each child is present and assign its height.
    // if either the children or the passed in node are NULL, assign 0.
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    // Return whichever is higher + 1;
    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(AVNode* p) {
    int hl, hr;
    // Check that each child is present and assign its height.
    // if either the children or the passed in node are NULL, assign 0.
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr; // Return the difference
}

AVNode* AVL::RInsert(AVNode* current, int key) {

    if (!current) {
        AVNode* child = new AVNode(key);
        child->height = 1;
        return child;
    }
    else if (key < current->data)
        current->lchild = RInsert(current->lchild, key);
    else if (key > current->data)
        current->rchild = RInsert(current->rchild, key);

    current->height = NodeHeight(current);
    // Check our height to know if we mu st perform rotations.
    // 2 means inbalance to the left.
    if (BalanceFactor(current) == 2) {
        // Left child 1 means imbalance comes from LL.
        if (BalanceFactor(current->lchild) == 1) {
            //return LLRotation(current);
        }
        // Left child -1 means imbalance comes from LR.
        else if (BalanceFactor(current->lchild) == -1) {
            //return LRRotation(current);
        }
    }
    // -2 means imbalance to the right.
    else if (BalanceFactor(current) == -2) {
        // Right child -1 means imbalance comes from RR.
        if (BalanceFactor(current->rchild) == -1) {
            //return RRRotation(current);
        }
        // Right child 1 means imbalance comes from RL.
        else if (BalanceFactor(current->rchild) == 1) {
            //return RLRotation(current);
        }
    }
    return current;
}