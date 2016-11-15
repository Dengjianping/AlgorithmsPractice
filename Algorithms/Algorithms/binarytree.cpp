#include "binarytree.h"

Binarytree::Binarytree(const int range)
{
	top = new TreeNode(this->rand_number(range));
}

Binarytree::Binarytree(const int range, const int number)
{
	top = new TreeNode(this->rand_number(range));

	vector<TreeNode*> v;
	v.push_back(top);

	for (size_t i = 0; i < number / 2; i++)
	{
		TreeNode* l = new TreeNode(this->rand_number(range));
		TreeNode* r = new TreeNode(this->rand_number(range));

		cout << l->data << ", " << r->data << ", ";

		if (l->data <= r->data)
		{
			v[i]->left = l;
			v[i]->right = r;
			v.push_back(l);
			v.push_back(r);
		}
		else
		{
			v[i]->left = r;
			v[i]->right = l;
			v.push_back(r);
			v.push_back(l);
		}
	}
	cout << endl;
}

void Binarytree::showNode(TreeNode* node) const
{
	if (node == NULL)return;
	cout << node->data << ", ";
}

TreeNode* Binarytree::topNode() const
{
	return top;
}

void Binarytree::visitLeft() const
{
	TreeNode* x = top;
	cout << "left leaves: ";
	while (x != NULL)
	{
		cout << x->data << ", ";
		x = x->left;
	}
	cout << endl;
}

void Binarytree::visitRight() const
{
	TreeNode* x = top;
	cout << "right leaves: ";
	while (x != NULL)
	{
		cout << x->data << ", ";
		x = x->right;
	}
	cout << endl;
}

void Binarytree::visitTree(TreeNode* node, this->showNode(node)) const
{
	if (node == NULL)return;
	if (node == this->top)
	{
		cout << this->top->data << ", ";
	}

	this->visitTree(node->left);
	cout << node->left->data << ", ";
	this->visitTree(node->right);
	cout << node->right->data << ", ";
}

int Binarytree::height(TreeNode* node)
{
	if (node == NULL)return 0;
	int l_height = this->height(node->left);
	int r_height = this->height(node->right);

	if (l_height >= r_height)return l_height + 1;
	else return r_height + 1;
}

int Binarytree::count(TreeNode* node)
{
	if (node == NULL)return 0;
	
	int l = this->count(node->left);
	int r = this->count(node->right);
	return l + 1 + r;
}

TreeNode* Binarytree::maxNode(TreeNode* node) const
{
	static TreeNode* tmp_node;
	if (node == NULL)return node;

	TreeNode* l_node = this->maxNode(node->left);
	TreeNode* r_node = this->maxNode(node->right);

	if (l_node->data >= node->data)
	{
		if (l_node->data >= node->data)
		{
			tmp_node = l_node;
			return l_node;
		}
	}
	else
	{
		if (r_node->data >= node->data)
		{
			tmp_node = r_node;
			return r_node;
		}
	}
	//return tmp_node;
}

Binarytree::~Binarytree()
{}