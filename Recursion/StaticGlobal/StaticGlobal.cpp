// StaticGlobal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int fun(int n) {
    static int x = 0;
    if (n > 0) {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main()
{
    int r;
    r = fun(5);
    std::cout << r << std::endl;

}
