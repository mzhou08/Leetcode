#include <stdio.h>
#include <vector>
#include <string>

class Solution {
public:
    int maxPower(std::string s) {
	int max = 0;
	int curr = 0;
	char prev = '\0';
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == prev) {
			curr++;
		} else {
			prev = s[i];
			curr = 1;
		}

		if (curr > max) max = curr;
	}

	return max;
    }
};
