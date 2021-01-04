/*Nguyen Nhat Minh Khoi*/
#pragma once
#include <vector>
#include "Node.h"

using namespace std;

class AVL
{
private:
	AVLNode* m_root;

	AVLNode* _leftRotation(AVLNode* root); // done
	AVLNode* _rightRotation(AVLNode* root); // done
	void _balance(AVLNode*& root); // done

	void _clear(AVLNode*& u); // done

	void _preOrder(AVLNode* root); // done
	void _inOrder(AVLNode* root); // done
	void _postOrder(AVLNode* root); // done

	AVLNode* _search(AVLNode* root, int key); // done
	void _insert(AVLNode*& root, int key); // done
	void _delMaxNode(AVLNode*& root, AVLNode*& tmp); // done
	void _remove(AVLNode*& root, int key); // done

	static bool _isAVL(AVLNode* root, int low, int high); // done
public:
	AVL(); // done
	AVL(vector<int> a); // done
	~AVL(); // done
	void clear(); // done

	AVLNode* root(); // done

	void preOrder(); // done
	void inOrder(); // done
	void postOrder(); // done
	void levelOrder(); // done

	AVLNode* search(int key); // done
	void insert(int key); // done
	void remove(int key); // done

	static bool isAVL(AVLNode* root); // done
};

