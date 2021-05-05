#include <iostream>
#include "DiagonalMatrix.h"
#include "LowTriMatrix.h"
int main()
{
    std::cout << "---- Diagonal Matrix ----\n";
    DiagonalMatrix dm(5);
    dm.Set(1, 1, 5);
    dm.Set(2, 2, 8);
    dm.Set(3, 3, 9);
    dm.Set(4, 4, 12);
    dm.Set(5, 5, 18);
    dm.Display();

    std::cout << "\n---- Lower Triangular Matrix ----\n";
    LowTriMatrix lt(5);

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            int r = rand() % 20 + 1;
            lt.Set(i, j, r);
        }
    }

    lt.Display();
}