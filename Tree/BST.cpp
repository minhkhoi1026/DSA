/*Nguyen Nhat Minh Khoi*/
#include "BST.h"
#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

/*PRIVATE AREA*/

void BST::_clear(BSTNode*& u) {
    if (!u) return;
    _clear(u->left);
    _clear(u->right);
    delete u;
}

void BST::_preOrder(BSTNode* root)
{
    if (!root) return;
    cout << root->key << " ";
    _preOrder(root->left);
    _preOrder(root->right);
}

void BST::_inOrder(BSTNode* root)
{
    if (!root) return;
    _inOrder(root->left);
    cout << root->key << " ";
    _inOrder(root->right);
}

void BST::_postOrder(BSTNode* root)
{
    if (!root) return;
    _postOrder(root->left);
    _postOrder(root->right);
    cout << root->key << " ";
}

BSTNode* BST::_search(BSTNode* root, int key) {
    if (!root) 
        return nullptr;
    if (key > root->key)
        return _search(root->right, key);
    if (key < root->key)
        return _search(root->left, key);
    return root;
}

void BST::_insert(BSTNode*& root, int key) {
    if (!root) {
        root = new BSTNode(key);
        return;
    }
    if (key > root->key)
        _insert(root->right, key);
    if (key < root->key)
        _insert(root->left, key);
}

void BST::_delMaxNode(BSTNode*& root, BSTNode*& tmp) {
    if (root->right)
        _delMaxNode(root->right, tmp);
    else {
        tmp->key = root->key;
        tmp = root;
        root = root->left;
    }
}

void BST::_remove(BSTNode*& root, int key) {
    if (!root)
        return;
    if (key > root->key)
        _remove(root->right, key);
    else if (key < root->key)
        _remove(root->left, key);
    else {
        // found key
        BSTNode* tmp = root;
        if (!root->left) root = root->right;
        else if (!root->right)
            root = root->left;
        else
            _delMaxNode(root->left, tmp);
        delete tmp;
    }
}

int BST::_height(BSTNode* root) {
    if (!root) return 0;
    return max(_height(root->left), _height(root->right)) + 1;
    return 0;
}

int BST::_countNode(BSTNode* root)
{
    if (!root) return 0;
    return _countNode(root->left) + _countNode(root->right) + 1;
    return 0;
}

int BST::_sumNode(BSTNode* root)
{
    if (!root) return 0;
    return _sumNode(root->left) + _sumNode(root->right) + root->key;
    return 0;
}

int BST::_heightNode(BSTNode* root, int val)
{
    if (!root)
        return -1;
    if (val > root->key)
        return _heightNode(root->right, val);
    if (val < root->key)
        return _heightNode(root->left, val);
    return _height(root);
}

int BST::_level(BSTNode* root, BSTNode* u)
{
    if (!root) return -1;
    
    if (u->key == root->key)
        return 1;

    int res;
    if (u->key < root->key)
        res = _level(root->left, u);
    else
        res = _level(root->right, u);
    if (res == -1)
        return res;
    else
        return res + 1;
    
}

int BST::_countLeaf(BSTNode* root)
{
    if (!root) return 0;
    // is leaf then return 1
    if (!root->left && !root->right)
        return 1;
    
    return _countLeaf(root->left) + _countLeaf(root->right);
}

int BST::_countLess(BSTNode* root, int val)
{
    if (!root)
        return 0;
    if (root->key >= val)
        return _countLess(root->left, val);
    // if root->key < val then result is 
    // number of node in left subtree + root + _countLess(root->right, val)
    return _countNode(root->left) + 1 + _countLess(root->right, val);
}

int BST::_countGreater(BSTNode* root, int val)
{
    if (!root)
        return 0;
    if (root->key <= val)
        return _countGreater(root->right, val);
    // if root->key > val then result is 
    // number of node in right subtree + root + _countGreater(root->left, val)
    return _countNode(root->right) + 1 + _countGreater(root->left, val);
}

bool BST::_isBST(BSTNode* root, int low, int high)
{
    // empty tree is BST
    if (!root) return true;
    // if not satisfy BST condition return false
    if (root->key > high || root->key < low)
        return false;
    // is BST if two subtree also BST
    return _isBST(root->left, low, root->key - 1) // avoid duplicate node 
        && _isBST(root->right, root->key + 1, high);
}

bool BST::_isFullBST(BSTNode* root, int low, int high)
{
    // empty tree is Full BST
    if (!root)
        return true;
    // leaf then return true
    if (!root->left && !root->right)
        return true;
    // have 1 child then return false
    if (!root->left || !root->right)
        return false;
    // if not satisfy BST condition return false
    if (root->key > high || root->key < low)
        return false;
    // is Full BST if two subtree also Full BST
    return _isFullBST(root->left, low, root->key - 1) 
        && _isFullBST(root->right, root->key + 1, high);
}

/*PUBLIC AREA*/

BST::BST() {
    m_root = nullptr;
}

BST::BST(vector<int> a) {
    m_root = nullptr;
    // insert each value in vector to tree
    for (int i = 0; i < a.size(); ++i)
        insert(a[i]);
}

BST::~BST() {
    clear();
}

void BST::clear() {
    _clear(m_root);
}

BSTNode* BST::root()
{
    return m_root;
}

void BST::preOrder() {
    _preOrder(m_root);
}

void BST::inOrder(){
    _inOrder(m_root);
}

void BST::postOrder() {
    _postOrder(m_root);
}

void BST::levelOrder() {
    queue<BSTNode*> q;
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
            BSTNode* cur = q.front();
            cout << cur->key << " ";
            q.pop();
            // push child of current node to queue for next level
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        cout << "\n";
    }
}

BSTNode* BST::search(int key) {
    return _search(m_root, key);
}

void BST::insert(int key) {
    _insert(m_root, key);
}

void BST::remove(int key) {
    _remove(m_root, key);
}

int BST::height() {
    return _height(m_root);
}

int BST::countNode()
{
    return _countNode(m_root);
}

int BST::sumNode()
{
    return _sumNode(m_root);
}

int BST::heightNode(int val)
{
    return _heightNode(m_root, val);
}

int BST::level(BSTNode* u)
{
    if (!u)
        return -1;
    else
        return _level(m_root, u);
}

int BST::countLeaf() {
    return _countLeaf(m_root);
}

int BST::countLess(int val) {
    return _countLess(m_root, val);
}

int BST::countGreater(int val) {
    return _countGreater(m_root, val);
}

bool BST::isBST(BSTNode* root) {
    return _isBST(root, INT_MIN, INT_MAX);
}

bool BST::isFullBST(BSTNode* root)
{
    return _isFullBST(root, INT_MIN, INT_MAX);
}
