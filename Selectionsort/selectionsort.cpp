#include <iostream>
#include <cstdlib>

using namespace std;

template <typename Type>
void initArray(Type* a, int N)
{
    for (size_t i = 0; i < N; i++)
    {
        a[i] = (Type)rand() % 30;
    }
}

template <typename Type>
void showArray(Type* a, int N)
{
    cout << endl << "------------" << endl;
    for (size_t i = 0; i < N; i++)
    {
        cout << a[i] << ", ";
    }
    cout << endl << "------------" << endl;
}

template <typename Type>
void swapValue(Type & x, Type & y)
{
    x ^=y;
    y ^=x;
    x ^=y;
}

template <typename Type>
void selectionSort(Type* a, int start, int end)
{
    for (size_t i = start; i < end; i++)
    {
        int min = i;
        for(size_t j = i + 1; j <= end; j++)
        {
            if (a[min] > a[j])min = j;
        }
        swapValue(a[min], a[i]);
    }
}

int main(int argc, char** argv)
{
    const int N = 10;
    int a[N];
    initArray(a, N);
    showArray(a, N);
    
    selectionSort(a, 0, N-1);
    showArray(a, N);
    
    return 0;
}