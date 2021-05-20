//
//  main.cpp
//  DataStructuresCpp
//
//  Created by Karen Rodriguez on 5/20/21.
//

#include <iostream>
#import "LinkedList.h"
#import "BinaryTree.h"
#import "BinarySearchTree.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    BST bestie = BST();
    bestie.root = bestie.RInsert(bestie.root, 8);
    bestie.Insert(9);
    bestie.Insert(10);
    bestie.Insert(3);
    bestie.Insert(2);
    bestie.Insert(5);
    bestie.RInsert(bestie.root, 7);
    bestie.Delete(bestie.root, 5);
    return 0;
}
