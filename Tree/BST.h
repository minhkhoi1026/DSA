/*Nguyen Nhat Minh Khoi*/
#pragma once
#include <vector>
#include "Node.h"

using namespace std;

class BST
{
private:
	BSTNode* m_root;

	void _clear(BSTNode*& u);

	void _preOrder(BSTNode* root);
	void _inOrder(BSTNode* root);
	void _postOrder(BSTNode* root);

	BSTNode* _search(BSTNode* root, int key);
	void _insert(BSTNode*& root, int key);
	void _delMaxNode(BSTNode*& root, BSTNode*& tmp);
	void _remove(BSTNode*& root, int key);

	int _height(BSTNode* root);
	int _countNode(BSTNode* root);
	int _sumNode(BSTNode* root);
	int _heightNode(BSTNode* root, int val);
	int _level(BSTNode* root, BSTNode* u);

	int _countLeaf(BSTNode* root);
	int _countLess(BSTNode* root, int val);
	int _countGreater(BSTNode* root, int val);
	
	static bool _isBST(BSTNode* root, int low, int high);
	static bool _isFullBST(BSTNode* root, int low, int high);
public:
	BST();
	BST(vector<int> a);
	~BST();
	void clear();

	BSTNode* root();

	void preOrder();
	void inOrder();
	void postOrder();
	void levelOrder();

	BSTNode* search(int key);
	void insert(int key);
	void remove(int key);

	int height();
	int countNode();
	int sumNode();
	int heightNode(int val);
	int level(BSTNode* u);

	int countLeaf();
	int countLess(int val);
	int countGreater(int val);

	static bool isBST(BSTNode* root);
	static bool isFullBST(BSTNode* root);
};

