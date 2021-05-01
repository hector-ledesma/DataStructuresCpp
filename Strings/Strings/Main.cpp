#include "./StringsSection.h"
#include <iostream>
int main()
{
    StringsSection impls = StringsSection();
    const char* str = "welcome";
    const char* str2 = "w4lC oMe";
    const char* str3 = "yeeehaaw";

    std::cout << impls.countString(str) << std::endl;
    impls.toggleCase(str);
    impls.toggleCase(str2);
    std::cout << impls.reverseString(str) << std::endl;
    std::cout << impls.compareStrings(str2, str) << std::endl;
    impls.dupesByBits(str3);
}