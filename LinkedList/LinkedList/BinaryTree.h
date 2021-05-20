#pragma once
class BTNode {
public:
	BTNode* lchild;
	int data;
	BTNode* rchild;


};

class BinaryTree
{
public:
	BTNode* root;

	BinaryTree();
	BinaryTree(int* arr, int len);
	BinaryTree(int* inorder, int *preorder, int inStart, int inEnd);
	void Preorder(BTNode* current);
	void Inorder(BTNode* current);
	void Postorder(BTNode* current);
	void Levelorder();
	void Height(BTNode* current);

	void PreorderIT();
	void InorderIT();
	void PostorderIT();
};

