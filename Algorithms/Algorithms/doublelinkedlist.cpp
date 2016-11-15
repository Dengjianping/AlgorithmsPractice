#include "doublelinkedlist.h"

DoubleLinkedList::DoubleLinkedList(const int range)
{
	head = new Node(this->rand_number(range));
	tail = head;
}

DoubleLinkedList::DoubleLinkedList(const int range, const int number)
{
	head = new Node(this->rand_number(range));
	Node* x = head;

	for (size_t i = 0; i < number; i++)
	{
		Node* y = new Node(this->rand_number(range));
		x->next = y;
		y->prev = x;
		x = y;
	}
	tail = x;
}

void DoubleLinkedList::addNode(Node* n)
{
	n->prev = tail;
	tail->next = n;
	tail = n;
}

void DoubleLinkedList::deleteNode(const int position)
{
	int count = 0;
	Node* x = head;

	while (x != NULL)
	{
		if (position == count) break;
		count++;
		x = x->next;
	}

	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
}

DoubleLinkedList::~DoubleLinkedList()
{}