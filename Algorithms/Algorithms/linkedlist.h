#pragma once
#include "algorithms.h"


struct Node
{
	int data;
	Node* next;
	Node(int value)
	{
		data = value;
		next = NULL;
	}
};

class LinkedList
{
private:
	Node* head;
	Node* tail;
public:
	LinkedList(const int range);
	LinkedList(const int number, const int range);
	int rand_number(const int range);
	void sort();
	void visitNode() const;
	void deleteNode(const int position);
	void addNode(Node* a);
	int countNode();
	~LinkedList();
};