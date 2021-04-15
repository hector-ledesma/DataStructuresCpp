// NaturalNumsSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int sum(int n) {
    if (n == 0) {
        return 0;
    }

    return sum(n - 1) + n;
}
int main()
{
    int r = sum(5);

    std::cout << r;
}

