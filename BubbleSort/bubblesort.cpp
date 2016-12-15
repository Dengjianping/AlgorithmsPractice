#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename Type>
void initArray(Type* a, const int N)
{
    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % ((Type)20);
    }
}

template <typename Type>
void swapValue(Type & a, Type & b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

template <typename Type>
void showArray(Type* a, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << ", ";
    }
    cout << endl;
}

template <typename Type>
void bubbleSort(Type* a, const int N)
{
    for (int i = 0; i < N; i++)
        for (int j = N-1; j > i; j--)
        {
            if (a[j] < a[j-1])
            {
                swapValue(a[j], a[j-1]);
            }
        }
}

int main()
{
    const int N = 10;
    static int a[N];
    srand((unsigned)time(NULL));
    initArray(a, N);
    showArray(a, N);
    bubbleSort(a, N);
    showArray(a, N);
    return 0;
}