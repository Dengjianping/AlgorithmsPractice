#pragma once
#include "algorithms.h"
//#include <gl\GLU.h>

#define Max 10000;

namespace dynamicprogramming
{
	const int M = Max;

	// use a general array to store caculated value
	int fibonacci(int n)
	{

		static int record[M];
		if (record[n] != 0)return record[n];
		if (n == 0)return 0;
		if (n == 1)return 1;

		int t = fibonacci(n - 1) + fibonacci(n - 2);
		record[n] = t;
		return t;
	}

	// use a vector to store caculated value, but the performance is a little lower than the former one
	int fibonacci_vector(int n)
	{
		static vector<int> v;
		if (n == 0)return 0;
		if (n == 1)return 1;

		if (n - 2 <= v.size() - 1 && v.size() != 0)
		{
			return v[n - 2];
		}

		int t = fibonacci_vector(n - 1) + fibonacci_vector(n - 2);
		v.push_back(t);
		return v[n - 2];
	}
}