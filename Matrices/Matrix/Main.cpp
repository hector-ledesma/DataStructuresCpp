#include <iostream>
#include "DiagonalMatrix.h"
#include "LowTriMatrix.h"
#include "SparseMatrix.h"
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

    std::cout << "\n---- Sparse Matrix ----\n";

    // Sparse Matrix #1
    std::cout << "\nSparse Matrix #1" << std::endl;
    Sparse s1 = Sparse();
    Element ele10 = Element{ 1,2,12 };
    s1.ele[0] = ele10;
    Element ele11 = Element{ 2,0,1 };
    s1.ele[1] = ele11;
    Element ele12 = Element{ 2,4,7 };
    s1.ele[2] = ele12;
    Element ele13 = Element{ 4,2,4 };
    s1.ele[3] = ele13;

    s1.Display();

    // Sparse Matrix #2
    std::cout << "\nSparse Matrix #2" << std::endl;
    Sparse s2 = Sparse();
    Element ele20 = Element{ 0,2,28 };
    s2.ele[0] = ele20;
    Element ele21 = Element{ 1,3,1 };
    s2.ele[1] = ele21;
    Element ele22 = Element{ 2,4,7 };
    s2.ele[2] = ele22;
    Element ele23 = Element{ 2,2,4 };
    s2.ele[3] = ele23;

    s2.Display();

    Sparse* sum = Sparse::add(&s1, &s2);

    sum->Display();
}