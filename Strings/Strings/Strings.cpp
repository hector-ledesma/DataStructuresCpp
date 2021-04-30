// Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    const char* s = "welcome";
    int i;
    for (i = 0; s[i] != '\0'; i++) {}
    std::cout << i << std::endl;
}
