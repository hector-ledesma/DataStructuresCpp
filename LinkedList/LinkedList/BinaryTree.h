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
	void Preorder(BTNode* current);
	void Postorder(BTNode* current);
	void Inorder(BTNode* current);
	void Levelorder(BTNode* current);
	void Height(BTNode* current);
};

