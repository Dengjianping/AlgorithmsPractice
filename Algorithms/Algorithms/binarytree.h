#pragma once
#include "algorithms.h"

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value)
	{
		data = value;
		left = right = NULL;
	}
};

class Binarytree
{
private:
	TreeNode* top;
public:
	Binarytree(const int range);
	Binarytree(const int range, const int number);
	TreeNode* topNode() const;
	int rand_number(const int range) { return rand() % range; };
	void showNode(TreeNode* node) const;
	void visitLeft() const;
	void visitRight() const;
	void visitTree(TreeNode* node, this->showNode) const;
	int height(TreeNode* node);
	int count(TreeNode* node);
	TreeNode* maxNode(TreeNode* node) const;
	~Binarytree();
};