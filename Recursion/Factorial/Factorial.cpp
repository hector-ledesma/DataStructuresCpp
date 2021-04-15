// Factorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int fact(int n) {
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}
int main()
{
    int r = fact(4);
    std::cout << r << std::endl;
}

