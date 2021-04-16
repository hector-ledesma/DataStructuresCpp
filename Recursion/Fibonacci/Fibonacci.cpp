
// Fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int fibIterative(int n) {
    int a = 0, b = 1, sum=0; 

    /*if (n == 1) {
        return a;
    }
    else if (n == 2) {
        return b;
    }*/
    if (n <= 1)
        return n;
    for (int i = 1; i < n; i++) {
        sum = a+b;
        a = b;
        b = sum;
    }
    return sum;
}

int fibExcessive(int n) {
    if (n <= 1)
        return n;

    return fibExcessive(n - 2) + fibExcessive(n - 1);
}

const int num = 6;
static int Arr[num +1];

int fib(int n) {
    
    if (n <= 1) {
        Arr[n] = n;
        return n;
    }

    if (Arr[n - 2] == -1)
        Arr[n - 2] = fib(n - 2);
    
    if (Arr[n - 1] == -1)
        Arr[n - 1] = fib(n - 1);

    Arr[n] = Arr[n - 2] + Arr[n - 1];
    return Arr[n];
}

int main()
{
    
    for (int i = 0; i <= num; i++) {
        Arr[i] = -1;
    }
    std::cout << fibIterative(num) << std::endl;
    std::cout << fibExcessive(num) << std::endl;
    std::cout << fib(num) << std::endl;

}