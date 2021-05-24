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
	int Height(AVNode* p);
	AVNode* InPre(AVNode* p);
	AVNode* InSucc(AVNode* p);
	AVNode* Delete(AVNode* p, int key);

	int NodeHeight(AVNode* p);
	int BalanceFactor(AVNode* p);
	AVNode* LLRotation(AVNode* p);
	AVNode* LRRotation(AVNode* p);
	AVNode* RLRotation(AVNode* p);
	AVNode* RRRotation(AVNode* p);
};

