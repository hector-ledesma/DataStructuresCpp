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
    else return -1;
}

// So this method assumes the string is all lower case. This makes it so we only need as many bits
// as there are letters = 25. So using a long(2 bytes) is enough to handle all of our comparisons.
// This is literally the same as finding dupe ints in an unsorted array, where we use a hashtable/set to
// add as we find, and whenever we reach a dupe we know it's not our first time seeing it.
// So I'm not too sure why use this instead of that? Since with this method we can't even count the amount of dupes but w/e

// Just realized that's precisely why we use this method. When count doesn't matter, (say if we just wanna find if 
// a single letter is a dupe) then this method consumed colossally less space in comparison.
void StringsSection::dupesByBits(const char* s) {
    long h = 0, x;

    for (int i = 0; s[i] != '\0'; i++) {
        x = 1;
        // We move one bit as many times as the index of the letter.
        x = x<<(s[i] - 97);
        // We use and to see if it's already there by ANDing it.
        if ((x & h) > 0)
            // If it is, we print it out.
            std::cout << s[i] << " is a duplicate." << std::endl;
        else
            // Otherwise, we add that bit to h/our hashtable by ORing it.
            h = x | h;
    }
}

// This function assumes that the length of both strings is the same and that it's all lower case.
// We use the same method of a hashmap that we used to count previously
// but this time, we first count up, and then count down.
// If we ever have an accessed index that isn't 0, then it's not an anagram.

void StringsSection::isAnagram(const char* s1, const char* s2) {
    // First make our hashmap/table
    int map[25] = { 0 };

    // Same method of accessing each index by subtracting 97.
    // Add one to that index, and we have the count for each letter by their alphabetical index.
    for (int i = 0; s1[i] != '\0'; i++)
        map[s1[i] - 97] += 1;

    // Do the same for the second string, but subtract at the index instead, and check that we never reach -1;
    for (int i = 0; s2[i] != '\0'; i++) {
        map[s2[i] - 97] -= 1;
        if (map[s2[i] - 97] == -1) {
            std::cout << s1 << " is not an anagram for " << s2 << std::endl;
            return;
        }
    }
    std::cout << s1 << " and " << s2 << " are anagrams." << std::endl;

}

// This method is nuts. The recursion is cool and all, but the trick is in checking
//      what letters do we have available for us to use at any given moment.
// At every layer of the recursion we're basically looping through the whole string from beginning to end.
// But for each layer that we go down, we let the program know that the previous letters aren't available
//      by having a look up table where we set 0 on available indices, letting us loop past those letters at the respective layer.
void StringsSection::permutations1(const char* s, int k) {
    // We're gonna need static arrays that will serve as our look up table and permutation build.
    // We're hardcoding 4 letter long strings for the sake of simplicity.
    static int A[4] = { 0 };
    static char res[4];
    
    // If we reached the end of our recursion, print our permutation build.
    if (s[k] == '\0') {
        std::cout << res << std::endl;
        return;
    }
    else {
        // We'll loop through the whole string at each layer.
        for (int i = 0; s[i] != '\0'; i++) {
            // But we only care about the ones available to us by checking our lookup table.
            if (A[i] == 0) {
                // Let the wolrd knows this letter is no longer available.
                A[i] = 1;
                // Add it to our permutation build.
                res[k] = s[i];
                // Go a layer deeper.
                permutations1(s, k + 1);
                // On our way back up, free up our current letter.
                A[i] = 0;
            }
        }
    }


}
