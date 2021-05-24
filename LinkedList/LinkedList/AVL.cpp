#include "AVL.h"
#include <iostream>

int AVL::NodeHeight(AVNode* p) {
    int hl, hr;
    // Check that each child is present and assign its height.
    // if either the children or the passed in node are NULL, assign 0.
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    // Return whichever is higher + 1;
    return hl > hr ? hl + 1 : hr + 1;
}

int AVL::BalanceFactor(AVNode* p) {
    int hl, hr;
    // Check that each child is present and assign its height.
    // if either the children or the passed in node are NULL, assign 0.
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr; // Return the difference
}

AVNode* AVL::LLRotation(AVNode* p) {
    AVNode* pl = p->lchild;
    AVNode* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr; // This confused me at first.
    // PLL is the culprit of our imbalance, but PLR is the victim.
    // P must be rotated right, which now misplaces PLR as P will be taking its place as PL's right child.
    // So where do we put plr? p's left child. Therefore we need to extract it so we can move it.
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl); // New Heights
    
    // Check if we just messed with our root, if so we need to change our root to PL
    if (root == p)
        root = pl;

    return pl;
}

AVNode* AVL::LRRotation(AVNode* p) {
    AVNode* pl = p->lchild;
    AVNode* plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (p == root) root = plr;
    return plr;
}

AVNode* AVL::RRRotation(AVNode* p) {
    AVNode* pr = p->rchild;
    AVNode* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl; // This confused me at first.
    // PLL is the culprit of our imbalance, but PLR is the victim.
    // P must be rotated right, which now misplaces PLR as P will be taking its place as PL's right child.
    // So where do we put plr? p's left child. Therefore we need to extract it so we can move it.
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr); // New Heights

    // Check if we just messed with our root, if so we need to change our root to PL
    if (root == p)
        root = pr;

    return pr;
}

AVNode* AVL::RLRotation(AVNode* p) {
    AVNode* pr = p->rchild;
    AVNode* prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl ->lchild;

    prl->lchild = p;
    prl->rchild = pr;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if (p == root) root = prl;
    return prl;
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
            return LLRotation(current);
        }
        // Left child -1 means imbalance comes from LR.
        else if (BalanceFactor(current->lchild) == -1) {
            return LRRotation(current);
        }
    }
    // -2 means imbalance to the right.
    else if (BalanceFactor(current) == -2) {
        // Right child -1 means imbalance comes from RR.
        if (BalanceFactor(current->rchild) == -1) {
            return RRRotation(current);
        }
        // Right child 1 means imbalance comes from RL.
        else if (BalanceFactor(current->rchild) == 1) {
            return RLRotation(current);
        }
    }
    return current;
}

int AVL::Height(AVNode* p) {
    if (!p) return 0;
    int x = Height(p->lchild);
    int y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

AVNode* AVL::InPre(AVNode* p) {
    while (p && p->rchild)
        p = p->rchild;
    return p;
}

AVNode* AVL::InSucc(AVNode* p) {
    while (p && p->lchild)
        p = p->lchild;
    return p;
}

// Delete method should remain exactly the same.
// All that should change is knowing when and how to rotate.
AVNode* AVL::Delete(AVNode* p, int key) {
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
        AVNode* q;
        if (Height(p->lchild) > Height(p->rchild)) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    // I think right here, once we're about to start returning our nodes after deletion, we should 
    //      check if we should rebalance.
    p->height = NodeHeight(p);
    // Check our height to know if we must perform rotations.
    // 2 means inbalance to the left.
    if (BalanceFactor(p) == 2) {
        // Left child 1 means imbalance comes from LL.
        if (BalanceFactor(p->lchild) == 1) {
            return LLRotation(p);
        }
        // Left child -1 means imbalance comes from LR.
        else if (BalanceFactor(p->lchild) == -1) {
            return LRRotation(p);
        }
        else {
            return LLRotation(p);
        }
    }
    // -2 means imbalance to the right.
    else if (BalanceFactor(p) == -2) {
        // Right child -1 means imbalance comes from RR.
        if (BalanceFactor(p->rchild) == -1) {
            return RRRotation(p);
        }
        // Right child 1 means imbalance comes from RL.
        else if (BalanceFactor(p->rchild) == 1) {
            return RLRotation(p);
        }
        else {
            return RRRotation(p);
        }
    }
    return p;
}