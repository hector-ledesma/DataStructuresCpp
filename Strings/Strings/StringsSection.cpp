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

char* StringsSection::reverseString(const char* s) {
    int sz = countString(s);
    char* str = new char[sz+1];
    // We want to move index i from last letter to first of og str.
    // And j from 0 to last of new str.
    for (int j = 0, i = sz - 1; i >= 0; i--, j++) {
        str[j] = s[i];
    }
    str[sz] = '\0';

    return str;
}

int StringsSection::compareStrings(const char* s1, const char* s2) {
    int i;
    // Go through both strings until we either reach the end of one, or find a letter that doesn't match.
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i]) break;

    // If they're the same = 0
    if (s1[i] == s2[i]) return 0;
    // If string 1 is greater = 1
    if (s1[i] > s2[i]) return 1;
    // If string 1 is smaller = -1
    if (s1[i] < s2[i]) return -1;

}