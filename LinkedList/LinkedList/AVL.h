#pragma once
class AVNode {
public:
	AVNode* lchild;
	int data;
	int height;
	AVNode* rchild;

	AVNode();
	AVNode(int d) { data = d; height = 0; lchild = rchild = nullptr; };
};
class AVL
{
public:
	AVNode* root;

	AVL() { root = nullptr; };
	AVNode* RInsert(AVNode* current, int key);
};

