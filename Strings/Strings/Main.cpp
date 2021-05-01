#include "./StringsSection.h"
#include <iostream>
int main()
{
    StringsSection impls = StringsSection();
    const char* str = "welcome";
    const char* str2 = "w4lC oMe";

    std::cout << impls.countString(str) << std::endl;
    impls.toggleCase(str);
    impls.toggleCase(str2);
}