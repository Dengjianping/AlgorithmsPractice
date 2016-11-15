#include "linkedlist.h"

LinkedList::LinkedList(const int range)
{
	head = new Node(this->rand_number(range));
	tail = head;
}

LinkedList::LinkedList(const int number, const int range)
{
	head = new Node(this->rand_number(range));
	Node* x = head;

	for (size_t i = 0; i < number; i++)
	{
		Node* y = new Node(this->rand_number(range));
		x->next = y;
		x = y;
	}

	tail = x;
}

int LinkedList::rand_number(int range)
{
	return rand() % range;
}

void LinkedList::sort()
{
	Node* x = head;
	int count = this->countNode();

}

void LinkedList::visitNode() const
{
	Node* x = head;

	while (x != NULL)
	{
		cout << x->data;
		if (x->next != NULL)
		{
			cout << ", ";
		}
		x = x->next;
	}
	cout << endl;
}

void LinkedList::deleteNode(const int position)
{
	Node* x = head;
	int count = 2;
	while (x != NULL)
	{
		if (count == position) break;
		count++;
		x = x->next;
	}

	x->next = x->next->next;
}

void LinkedList::addNode(Node* a)
{
	Node* x = tail;
	x->next = a;
	tail = a;
}

int LinkedList::countNode()
{
	Node* x = head;
	int count = 0;

	while (x != NULL)
	{
		count++;
		x = x->next;
	}
	return count;
}

LinkedList::~LinkedList()
{}