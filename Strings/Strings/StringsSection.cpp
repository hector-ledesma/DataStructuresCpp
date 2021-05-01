#include "./StringsSection.h"
#include <iostream>

int StringsSection::countString(const char* s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {}
    return i;
}

char* StringsSection::copyString(const char* s) {
    int size = countString(s);
    char* writable = new char[size + 1];
    for (int i = 0; i <= size; i++)
        writable[i] = s[i];
    return writable;
}

void StringsSection::toggleCase(const char* s) {
    
    char* writable = copyString(s);

    for (int i = 0; writable[i] != '\0'; i++) {
        // Check if it's uppercase
        if (writable[i] >= 65 && writable[i] <= 90)
            writable[i] += 32;
        else if (writable[i] >= 'a' && writable[i] <= 'z')
            writable[i] -= 32;
    }

    std::cout << writable << std::endl;

    delete[] writable;
}