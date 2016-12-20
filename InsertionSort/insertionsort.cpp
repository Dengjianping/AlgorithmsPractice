#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename type>
void initArray(type* a, const int N) {
    for (size_t i = 0; i < N; i++) {
        a[i] = rand() % ((type)20);
    }
}

template <typename type>
void showArray(type* a, const int N) {
    for (size_t i = 0; i < N; i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}

template <typename type>
void swapValue(type & a, type & b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

template <typename type>
void insertionSort(type* a, int start, int end) {
    // let the minimized value be located at first
    for (size_t i = end; i >= start + 1; i--) {
        if (a[i] < a[i-1])swapValue(a[i], a[i-1]);
    }
    // 
    for (size_t i = start + 2; i <= end; i++) {
        size_t j = i; type v = a[i];
        for (; j > start + 1; j--) {
            if (v < a[j-1]) {
                a[j] = a[j-1]; // move the elements to right
                continue;
            }
            else break;
        }
        a[j] = v;
    }
}

int main(int argc, char** argv)
{
    // srand((unsigned)time(NULL));
    const int N = 10;
    static int a[N];
    initArray(a, N);
    showArray(a, N);
    
    insertionSort(a, 0, N-1);
    showArray(a, N);
    return 0;
}