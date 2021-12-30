#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
  std::string countAndSay(int n) {
    if (n == 1) {
      
      return "1";

    } else {
      
      std::string prev = countAndSay(n-1);
      std::string res = "";
      char curr = prev[0];
      char count = 1;

      for (int i = 1; i < prev.length(); i++) {
        if (prev[i] == curr) {
          count ++;
	} else {
          std::string to_add = to_string(count) + curr;
          cout << to_add;

	  res = res + to_add;
	  curr = prev[i];
	  count = 1;
	}
      }
      
      std::string to_add = to_string(count) + curr;
      res = res + to_add;

      return res;
    }
  }
};
