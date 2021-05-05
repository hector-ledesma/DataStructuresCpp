#include "./StringsSection.h"
#include <iostream>
int main()
{
    StringsSection impls = StringsSection();
    const char* str = "welcome";
    const char* str2 = "w4lC oMe";
    const char* str3 = "yeeehaaw";
    const char* str4 = "clemowe";
    const char* str5 = "emil";

    std::cout << impls.countString(str) << std::endl;
    impls.toggleCase(str);
    impls.toggleCase(str2);
    std::cout << impls.reverseString(str) << std::endl;
    std::cout << impls.compareStrings(str2, str) << std::endl;
    impls.dupesByBits(str3);
    impls.isAnagram(str2, str);
    impls.isAnagram(str, str4);
    std::cout << "----- Permutations Map -----" << std::endl;
    impls.permutationsMap(str5, 0);
    std::cout << "------------------------" << std::endl;

    std::cout << "----- Permutations Swap -----" << std::endl;
    char* editable = impls.copyString(str5);
    impls.permutationsSwap(editable, 0);
    std::cout << "------------------------" << std::endl;
}