#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename Type>
void initArray(Type *a, int N)
{
    for (size_t i = 0;i < N; i++)
    {
        a[i] = (Type)(rand() % 20);
    }
}

template <typename Type>
void showArray(Type* a, int N)
{
    cout << endl << "-----------" << endl;
    for (size_t i = 0; i < N; i++)
    {
        cout << a[i] << ", ";
    }
    cout << endl << "-----------" << endl;
}

template <typename Type>
void swapValue(Type & x, Type & y)
{
    x ^=y;
    y ^=x;
    x ^=y;
}

template <typename Type>
int partition(Type* a, int start, int end)
{
    int flag = end; int i = start, j = end - 1;
    for (;;)
    {
        for (; i <= end; i++)
        {
            if (a[i] >= a[flag]) break;
        }
        for (; j >= start; j--)
        {
            if (a[j] <= a[flag]) break;
        }
        if (i >= j) break;
        swapValue(a[i], a[j]);
    }
    swapValue(a[i], a[flag]);
    return i;
}

template <typename Type>
void quickSort(Type* a, int start, int end)
{
    if (start >= end) return;
    int i = partition(a, start, end);
    cout << i << endl;
    quickSort(a, start, i - 1);
    quickSort(a, i + 1, end);
}

int main(int argc, char** argv)
{
    srand((unsigned)time(NULL));
    const int N = 10;
    int a[N];
    initArray(a, N);
    showArray(a, N);
    
    //int i = partition(a, 0, N-1);
    //cout << i << endl;
    quickSort(a, 0, N-1);
    showArray(a, N);
    
    return 0;
}