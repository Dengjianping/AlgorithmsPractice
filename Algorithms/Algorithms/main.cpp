#include "algorithms.h"
#include "linkedlist.h"
#include "binarytree.h"

int main()
{
	int range = 100;
	int number = 10;
	auto t1 = chrono::steady_clock::now();
	LinkedList l = LinkedList(number, range);
	l.visitNode();
	system("pause");

	Binarytree b(range, number);
	//cout << 
	b.visitLeft();
	b.visitRight();
	TreeNode* node = b.topNode();
	cout << "node count: " << b.count(node) << endl;
	cout << "tree height: " << b.height(node) << endl;
	//TreeNode* max_node = b.maxNode(node);
	//cout << "max node: " << max_node->data << endl;
	//cout << "visit node: " << b.visitTree(node) << endl;
	b.visitTree(node);
	//auto t2 = chrono::steady_clock::now();
	//cout << point::run_time(t1, t2) << endl;
	system("pause");
	return 0;
}