#pragma once
#include "algorithms.h"

void merge_sort(int c[], int a[], const int N, int b[], const int M)
{
	for (size_t k = 0, i = 0, j = 0; k < N + M; k++)
	{
		if (i == N)
		{
			c[k] = b[++j];
			continue;
		}
		if (j == M)
		{
			c[k] = a[++i];
			continue;
		}
		//c[k] = (a[i] < b[j]) ? a[i++] : b[j++];
		if (a[i] < b[j])
		{
			c[k] = a[i];
			i++;
		}
		else
		{
			c[k] = b[j];
			j++;
		}
	}
}

void variant_merge_sort()