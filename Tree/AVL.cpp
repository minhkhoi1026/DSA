/*Nguyen Nhat Minh Khoi*/
#include "AVL.h"
#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

/*PRIVATE AREA*/

AVLNode* AVL::_leftRotation(AVLNode* root)
{
    AVLNode* child = root->left;
    // apply rotation
    root->left = child->right;
    child->right = root;

    // update new height
    root->updateHeight();
    child->updateHeight();
    return child;
}

AVLNode* AVL::_rightRotation(AVLNode* root)
{   
    AVLNode* child = root->right;
    // apply rotation
    root->right = child->left;
    child->left = root;

    // update new height
    root->updateHeight();
    child->updateHeight();
    return child;
}

void AVL::_balance(AVLNode*& root)
{
    // empty tree is balance
    if (!root)
        return;

    int balanced_factor = root->balanceFactor();
    // if current tree is already balanced then we don't need to do anything
    root->updateHeight();
    if (abs(balanced_factor) <= 1)
        return;

    //left left case
    else if (balanced_factor > 1 && root->left->balanceFactor() >= 0) {
        root = _leftRotation(root);
    }

    //right right case
    else if (balanced_factor < -1 && root->right->balanceFactor() < 0) {
        root = _rightRotation(root);
    }

    //left right case
    else if (balanced_factor > 1 && root->left->balanceFactor() < 0) {
        root->left = _rightRotation(root->left);
        root = _leftRotation(root);
    }

    //right left case
    else if (balanced_factor < -1 && root->right->balanceFactor() >= 0) {
        root->right = _leftRotation(root->right);
        root = _rightRotation(root);
    }
}

void AVL::_clear(AVLNode*& u) {
    if (!u) return;
    _clear(u->left);
    _clear(u->right);
    delete u;
}

void AVL::_preOrder(AVLNode* root)
{
    if (!root) return;
    cout << root->key << " ";
    _preOrder(root->left);
    _preOrder(root->right);
}

void AVL::_inOrder(AVLNode* root)
{
    if (!root) return;
    _inOrder(root->left);
    cout << root->key << " ";
    _inOrder(root->right);
}

void AVL::_postOrder(AVLNode* root)
{
    if (!root) return;
    _postOrder(root->left);
    _postOrder(root->right);
    cout << root->key << " ";
}

AVLNode* AVL::_search(AVLNode* root, int key) {
    if (!root)
        return nullptr;
    if (key > root->key)
        return _search(root->right, key);
    if (key < root->key)
        return _search(root->left, key);
    return root;
}

void AVL::_insert(AVLNode*& root, int key) {
    if (!root) {
        root = new AVLNode(key);
        return;
    }
    if (key > root->key)
        _insert(root->right, key);
    else if (key < root->key)
        _insert(root->left, key);
    else // key == root->key
        return;
    // update new root after balance tree
    _balance(root);
}

void AVL::_delMaxNode(AVLNode*& root, AVLNode*& tmp) {
    if (root->right) {
        _delMaxNode(root->right, tmp);
    }
    else {
        tmp->key = root->key;
        tmp = root;
        root = root->left;
        delete tmp;
        tmp = nullptr;
    }
    _balance(root);
    //cout << "Current Node" << (root ? root->key : -1) << "\n";
    //cout << "Level-order traversal: ";  levelOrder();
    //cout << "\n";
}

void AVL::_remove(AVLNode*& root, int key) {
    if (!root)
        return;
    if (key > root->key)
        _remove(root->right, key);
    else if (key < root->key)
        _remove(root->left, key);
    else {
        // found key
        AVLNode* tmp = root;
        if (!root->left) {
            root = root->right;
            delete tmp;
            tmp = nullptr;
        }
        else if (!root->right) {
            root = root->left;
            delete tmp;
            tmp = nullptr;
        }
        else
            _delMaxNode(root->left, tmp);
    }
    _balance(root);
    //cout << "Current Node" << (root ? root->key : -1) << "\n";
    //cout << "Level-order traversal: ";  levelOrder();
    //cout << "\n";
}

bool AVL::_isAVL(AVLNode* root, int low, int high)
{
    // empty tree is AVL
    if (!root) return true;
    // if not satisfy BST condition return false
    if (root->key > high || root->key < low)
        return false;
    // if not satisfy balanced condition return false
    if (abs(root->balanceFactor()) > 1)
        return false;
    // is AVL if two subtree also AVL
    return _isAVL(root->left, low, root->key - 1) // avoid duplicate node 
        && _isAVL(root->right, root->key + 1, high);
}

/*PUBLIC AREA*/

AVL::AVL() {
    m_root = nullptr;
}

AVL::AVL(vector<int> a) {
    m_root = nullptr;
    // insert each value in vector to tree
    for (int i = 0; i < a.size(); ++i)
        insert(a[i]);
}

AVL::~AVL() {
    clear();
}

void AVL::clear() {
    _clear(m_root);
}

AVLNode* AVL::root()
{
    return m_root;
}

void AVL::preOrder() {
    _preOrder(m_root);
}

void AVL::inOrder() {
    _inOrder(m_root);
}

void AVL::postOrder() {
    _postOrder(m_root);
}

void AVL::levelOrder() {
    queue<AVLNode*> q;
    int current_level = 1;
    // at initial, push root to queue
    if (m_root) q.push(m_root);

    // BFS through the tree to get level
    while (q.size()) {
        cout << "Level " << current_level++ << ": ";

        // pop all node of current level
        int current_size = q.size();
        while (current_size--) {
            // pop and write current node
            AVLNode* cur = q.front();
            cout << cur->key << " ";
            q.pop();
            // push child of current node to queue for next level
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        cout << "\n";
    }
}

AVLNode* AVL::search(int key) {
    return _search(m_root, key);
}

void AVL::insert(int key) {
    _insert(m_root, key);
}

void AVL::remove(int key) {
    _remove(m_root, key);
}

bool AVL::isAVL(AVLNode* root) {
    return _isAVL(root, INT_MIN, INT_MAX);
}
