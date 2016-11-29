#include <iostream>
#include <cstdlib>

using namespace std;

template <typename Type>
void initArray(Type* a, int N)
{
    for size_t i = 0; i < N; i++)
    {
        a[i] = (Type)rand() % 20;
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
void swapValue(Type & x, Type & x)
{
    x ^=y;
    y ^=x;
    x ^=y;
}

template <typename Type>
void selectionSort(Type* a, int start, int end)
{
    Type min;
    for (size_t i = start; i < end; i++)
    {
        min = a[i];
        for(size_t j = i + 1; j < end; j++)
        {
            if (min > a[j])swapValue(min, a[j]);
        }
    }
}

int main(int argc, char** argv)
{
    const int N = 10;
    int a[N];
    initArray(a, N);
    showArray(a, N);
    
    selectionSort(a, 0, N);
    showArray(a, N);
    
    return 0;
}