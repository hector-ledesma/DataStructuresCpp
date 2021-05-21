//
//  BinarySearchTree.hpp
//  DataStructuresCpp
//
//  Created by Karen Rodriguez on 5/20/21.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>

class BSTNode {
public:
    BSTNode* lchild;
    int data;
    BSTNode* rchild;
    BSTNode(){lchild=rchild=nullptr;data=0;};
    BSTNode(int k){data=k;lchild=rchild=nullptr;};
};

class BST {
public:
    BSTNode* root;
    
    BST(){root = nullptr;}

    void Insert(int key);
    void Inorder(BSTNode* current);
    BSTNode* Search(int key);

    BSTNode* RInsert(BSTNode *p, int key);
    int Height(BSTNode* p);
    BSTNode* InPre(BSTNode* p);
    BSTNode* InSucc(BSTNode* p);
    BSTNode* Delete(BSTNode *p, int key);
};

#endif /* BinarySearchTree_hpp */
