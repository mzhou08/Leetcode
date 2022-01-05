#include <string>
#include <vector>
#include <iostream>

/*
Runtime: 9 ms, faster than 37.11% of C++ online submissions for Count and Say.
Memory Usage: 6.5 MB, less than 76.70% of C++ online submissions for Count and Say.
*/

class Solution {
public:
  std::string countAndSay(int n) {
    if (n == 1) return "1";
    if (n == 2) return "11";

    std::string prev = countAndSay(n-1);
    std::string res = "";
    int count = 1;
    int len = prev.size();

    for (int i = 1; i < len; i++) {
      if (prev[i] == prev[i -1]) {
        count++;
      } else {
        res += '0' + count;
        res += prev[i-1];
        count = 1;
      }

      if (i == len - 1) {

        res += '0' + count;
        res += prev[i];
      }
    }
    return res;
  }
};