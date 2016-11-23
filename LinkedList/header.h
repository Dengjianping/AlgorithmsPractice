#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
T randNumber(T range)
{
    return rand() % range;
}