#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<long> stack(0);

        for (string tok: tokens) {
            if (tok == "*") {
                long y = stack.back(); stack.pop_back();
                long x = stack.back(); stack.pop_back();
                
                stack.push_back(x * y);
            } else if (tok == "+") {
                long y = stack.back(); stack.pop_back();
                long x = stack.back(); stack.pop_back();
                
                stack.push_back(x + y);
            } else if (tok == "/") {
                long y = stack.back(); stack.pop_back();
                long x = stack.back(); stack.pop_back();
                
                stack.push_back(x / y);
            } else if (tok == "-") {
                long y = stack.back(); stack.pop_back();
                long x = stack.back(); stack.pop_back();
                
                stack.push_back(x - y);
            } else {
                long tok_int = stoi(tok);

                stack.push_back(tok_int);
            }
        }

        return stack.back();
    }
};