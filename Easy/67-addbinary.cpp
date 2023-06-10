class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(); int n = b.size();

        int newLen = max(m, n);

        a.insert(0, newLen - m, '0');
        b.insert(0, newLen - n, '0');

        bool carry = false;

        string res = "";

        for (int i = newLen - 1; i >= 0; i--) {
            bool a_1 = a[i] == '1';
            bool b_1 = b[i] == '1';
            
            if (a_1 + b_1 + carry >= 2) {
                
                if (a_1 + b_1 + carry == 3) {
                    res += '1';
                } else {
                    res += '0';
                }

                carry = true;
            } else {
                
                if (a_1 + b_1 + carry == 1) {
                    res += '1';
                } else {
                    res += '0';
                }
                
                carry = false;
            }
        }

        if (carry) {
            res += '1';
        }

        reverse(res.begin(), res.end());

        return res;
    }
};