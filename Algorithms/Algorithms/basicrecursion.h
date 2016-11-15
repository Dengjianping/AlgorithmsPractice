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

int log_2(int n)
{
	if (n % 2 != 0 && n / 2 < 2)return 0;
	return log_2(n / 2) + 1;
}

int maxNode(Node* node)
{
	if (node->next == NULL)return node->data;
	if (node->data > maxNode(node->next))return node->data;
	else return maxNode(node->next);
}

int factorial(int n)
{
	if (n == 0)return 1;
	return n*factorial(n - 1);
}

int Fibonacci(int n)
{
	if (n == 0)return 0;
	if (n == 1)return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}