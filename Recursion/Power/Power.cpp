// Power.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int powerLinear(int m, int n) {
    if (n == 0)
        return 1;
    return powerLinear(m, n - 1) * m;
}

int powerOptimal(int m, int n) {
    if (n == 0)
        return 1;

    if (n % 2 == 0) {
        return powerOptimal(m * m, n / 2);
    }
    else if (n % 2 == 1) {
        return m * powerOptimal(m * m, (n-1) / 2);
    }
}

int main()
{
    std::cout << powerOptimal(2, 5);
}