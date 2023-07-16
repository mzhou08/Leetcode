class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> elems = unordered_set<int>(
            arr.begin(), arr.end()
        );

        return count_if(
            arr.begin(),
            arr.end(),
            [&elems](int a) {
                return elems.find(a + 1) != elems.end();
            }
        );
    }
};