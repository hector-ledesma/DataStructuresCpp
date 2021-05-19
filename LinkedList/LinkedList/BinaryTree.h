#pragma once
class BTNode {
public:
	BTNode* lchild;
	int data;
	BTNode* rchild;


};
class BTQueue
{
private:
	BTNode* head;
	BTNode* tail;
public:
	BTQueue();
	void queue(BTNode x);
	BTNode* dequeue();
	void Display();
};
class BinaryTree
{
public:
	BTNode* root;

	BinaryTree();
	BinaryTree(int* arr, int len);
	void Preorder();
	void Postorder();
	void Inorder();
	void Levelorder();
	void Height();
};

