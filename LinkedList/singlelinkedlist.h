#pragma once
#include "header.h"

template <class T>
struct LinkedList
{
    T value;
    LinkedList* next;
    LinkedList(T v)
    {
        value = v; next = NULL;
    }
};

template <class T>
void createLinkedList(LinkedList<T>* head, T range, const int countOfNodes)
{
    LinkedList<T>* x = head;
    for (size_t i = 0; i < countOfNodes-1; i++)
    {
        LinkedList<T>* t = new LinkedList<T>(randNumber(range));
        x->next = t;
        x = t;
    }
}

// length of linked list
template <class T>
int count(LinkedList<T>* x)
{
    if (x->next == NULL)return 1;
    return 1 + count(x->next);
}

// delete a specified node adjcent
template <class T>
void deleteNode(LinkedList<T>*x)
{
    x->next = x->next->next;
}

template <class T>
void addNode(LinkedList<T>* location, LinkedList<T>* insertedNode)
{
    insertedNode->next = location->next->next;
    location->next = insertedNode;
}

template <class T>
void visitLinkedList(LinkedList<T>* x)
{
    cout << x->value << ", ";
    if (x->next == NULL)return;
    visitLinkedList(x->next);
}

template <class T>
LinkedList<T>* maxNode(LinkedList<T>* x)
{
    LinkedList<T>* maxNode = x;
    while (x != NULL)
    {
        x = x->next;
        while (x!=NULL)
        {
            if (maxNode->value < x->value)
            {
                maxNode = x;
            }
            x = x->next;
        }
    }
    return maxNode;
}

template <class T>
LinkedList<T>* minNode(LinkedList<T>* x)
{
    LinkedList<T>* minNode = x;
    while (x != NULL)
    {
        x = x->next;
        while (x != NULL)
        {
            if (minNode->value > x->value)
            {
                minNode = x;
            }
            x = x->next;
        }
    }
    return minNode;
}

/*template <class T>
LinkedList<T>* createLinkedList(LinkedList<T>* x)
{}*/

template <class T>
void reverseLinkedList(LinkedList<T>* x)
{}