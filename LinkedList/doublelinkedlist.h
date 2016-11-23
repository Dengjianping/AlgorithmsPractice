#pragma once
#include "header.h"

template <class T>
struct DoubleLinkedList
{
    T value;
    DoubleLinkedList* pre, next;
    DoubleLinkedList(T v)
    {
        value = n;
        pre = next = NULL;
    }
};
