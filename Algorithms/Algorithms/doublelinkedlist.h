#pragma once
#include "algorithms.h"

struct Node
{
	int data;
	Node* next;
	Node* prev;
	Node(int value)
	{
		data = value;
		next = prev = NULL;
	}
};

class DoubleLinkedList
{
private:
	Node* head;
	Node* tail;
public:
	DoubleLinkedList(const int range);
	DoubleLinkedList(const int range, const int number);
	int rand_number(const int range) { return rand() % range; };
	void addNode(Node* n);
	void deleteNode(const int position);
	~DoubleLinkedList();
};