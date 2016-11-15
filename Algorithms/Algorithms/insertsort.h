#pragma once
#include "algorithms.h"

void insert_sort(int a[], int length)
{
	for (size_t i = 0; i < length; i++)
	{
		int j = i + 1;
		int key = a[j];
		while (i > 0 && key > a[i])
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i] = key;
	}
}