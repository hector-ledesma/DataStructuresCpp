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
private:
    BSTNode* root;
public:
    BST(){root = nullptr;}
    BSTNode* getRoot(){return root;}
    void Insert(int key);
    void Inorder(BSTNode* current);
    BSTNode* Search(int key);
};

#endif /* BinarySearchTree_hpp */
