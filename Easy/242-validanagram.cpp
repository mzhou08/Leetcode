#include <unordered_map>
#include <string>

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> schars;
        std::unordered_map<char, int> tchars;
        
        if (s.size() != t.size()) {return false;}
        for (int i = 0; i < s.size(); i++) {
            schars[s[i]]++;
            tchars[t[i]]++;
        }
        
        return schars == tchars;
    }
};