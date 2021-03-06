#pragma once

class StringsSection {
public:
	int countString(const char* s);
	char* copyString(const char* s);
	void toggleCase(const char* s);
	char* reverseString(const char* s);
	int compareStrings(const char* s1, const char* s2);
	void dupesByBits(const char* s);
	void isAnagram(const char* s1, const char* s2);
	void permutationsMap(const char* s, int k);
	void permutationsSwap(char* s, int l);
	void swap(char *c1, char* c2);
};