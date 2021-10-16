#include <math.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (0 <= x && x <= 9) {
            return true;
        } else if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        } else if (x > 0) {
            int rev = 0;
            while (x > rev) {
                rev = rev * 10 + (x % 10);
                x = x / 10;
            }
            if (rev == x || rev / 10 == x) {
                return true;
            }
        }
        return false;
    }
};