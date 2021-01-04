/*Nguyen Nhat Minh Khoi*/
#include <iostream>
#include "BST.h"
#include "AVL.h"

using namespace std;

void demoBST() {
	vector<int> a = { 13, 17, 29, 10, 2, 100, 1, 7, 9, 6, 28, 11, 16 };
	BST obj(a);

	if (obj.search(8))
		cout << "Found!\n";
	else
		cout << "Not found!\n";
	obj.remove(17);

	cout << "Level-order traversal: ";  obj.levelOrder();

	cout << "In-order traversal: "; obj.inOrder(); cout << "\n";

	cout << "Pre-order traversal: ";  obj.preOrder(); cout << "\n";

	cout << "Post-order traversal: ";  obj.postOrder(); cout << "\n";

	cout << "Number of node: " << obj.countNode() << "\n";

	cout << "Number of leaf: " << obj.countLeaf() << "\n";

	cout << "- Number of node greater than 15: " << obj.countGreater(15) << "\n";

	cout << "- Number of node less than 7: " << obj.countLess(7) << "\n";

	cout << "- Height: " << obj.height() << "\n";

	cout << "- Number of node: " << obj.countNode() << "\n";

	cout << "- Sum of node: " << obj.sumNode() << "\n";

	cout << "- Height of each node in tree:\n";
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " -> height = " << obj.heightNode(a[i]) << "\n";

	cout << "- Level of each node in tree:\n";
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " -> level = " << obj.level(obj.search(a[i])) << "\n";

	cout << "- Is BST: " << BST::isBST(obj.root()) << "\n";
	cout << "- Is Full BST: " << BST::isFullBST(obj.root()) << "\n";
}

void demoAVL() {
	vector<int> a = { 50, 70, 90, 80, 85, 75, 30, 60, 55, 52, 58, 56 };
	AVL obj(a);
	/*for (int i = 0; i < a.size(); i++) {
		obj.insert(a[i]);
		cout << "Key: " << a[i] << "\n";
		cout << "Level-order traversal: ";  obj.levelOrder();
		cout << "\n";
	}*/

	if (obj.search(11))
		cout << "Found!\n";
	else
		cout << "Not found!\n";
	obj.remove(30);
	obj.remove(50);
	obj.remove(55);

	cout << "Level-order traversal: ";  obj.levelOrder();

	cout << "In-order traversal: "; obj.inOrder(); cout << "\n";

	cout << "Pre-order traversal: ";  obj.preOrder(); cout << "\n";

	cout << "Post-order traversal: ";  obj.postOrder(); cout << "\n";

	cout << "- Is AVL: " << AVL::isAVL(obj.root()) << "\n";
}

int main() {
	//demoBST();
	demoAVL();
	return 0;
}