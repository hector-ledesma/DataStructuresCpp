#include "Stack1.h"
#include <iostream>

Stack1::Stack1(int sz) {
	top = -1;
	size = sz;
	s = new int[sz];
}