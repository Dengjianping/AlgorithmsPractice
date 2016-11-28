#pragma once
#include "header.h"

template <class T>
struct DoubleLinkedList
{
    T value;
    DoubleLinkedList* prev, next;
    DoubleLinkedList(T v)
    {
        value = n;
        prev = next = NULL;
    }
};

template <class T>
void createDoubleLinkedList(const int countOfNodes, DoubleLinkedList<T>* head)
{
    DoubleLinkedList<T>* x = head;
    for (size_t i = 0; i < countOfNodes; i++)
    {
        DoubleLinkedList<T>* t = new DoubleLinkedList<T>(randNumber());
        x->next = t;
        t->prev = x;
        x = t;
    }
}

template <class T>
void deleteNode(DoubleLinkedList<T>* specified)
{
    specified->prev->next = specified->next;
    specified->next->prev = specified->prev;
}

template <class T>
void addNode(DoubleLinkedList<T>* location, DoubleLinkedList<T>* newNode)
{
    DoubleLinkedList<T>* temp = location->next;
    location->next = newNode;
    newNode->next = temp;
    temp->prev = newNode;
}