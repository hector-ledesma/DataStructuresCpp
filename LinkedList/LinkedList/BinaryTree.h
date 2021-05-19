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
};

