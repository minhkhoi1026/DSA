#pragma once
#include <math.h>

using namespace std;

class BSTNode
{
public:
	int key;
	BSTNode* left;
	BSTNode* right;
	BSTNode(int data) {
		key = data;
		left = right = nullptr;
	}
	BSTNode(int data, BSTNode* t_left, BSTNode* t_right) {
		key = data;
		left = t_left;
		right = t_right;
	}
};

class AVLNode
{
private:
	static int _height(AVLNode* root) {
		return (root) ? root->height : 0;
	}
public:
	int key;
	int height;
	AVLNode* left;
	AVLNode* right;

	AVLNode(int data) {
		key = data;
		left = right = nullptr;
		height = 1;
	}

	AVLNode(int data, AVLNode* t_left, AVLNode* t_right) {
		key = data;
		left = t_left;
		right = t_right;
		height = 1;
	}
	
	int balanceFactor() {
		return _height(left) - _height(right);
	}

	void updateHeight() {
		height = 1 + max(_height(left), _height(right));
	}
};
