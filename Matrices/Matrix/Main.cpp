#include <iostream>
#include "DiagonalMatrix.h"
int main()
{
    std::cout << "Hello World!\n";
    DiagonalMatrix m(4);
    m.Set(1, 1, 5);
    m.Set(2, 2, 8);
    m.Set(3, 3, 9);
    m.Set(4, 4, 12);
    m.Display();
}