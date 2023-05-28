class Solution {
public:
    bool compareCounts(int *s_counts, int *p_counts) {
        for (int i = 0; i < 26; i++) {
            if (s_counts[i] != p_counts[i]) {
                return false;
            }
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        // need to track the character counts at each point,
        // of the last |p| characters.

        int *s_counts = (int*) calloc(sizeof(int), 26);
        int *p_counts = (int*) calloc(sizeof(int), 26);

        for (auto &c : p) {
            p_counts[
                ((int) c) - ((int) 'a')
            ]++;
        }

        int k = p.size();
        vector<int> res;

        for (int i = 0; i < s.size(); i++) {
            s_counts[
                ((int) s[i]) - ((int) 'a')
            ]++;
    
            if (i >= k) {
                s_counts[
                    ((int) s[i - k]) - ((int) 'a')
                ]--;
            }

            if (compareCounts(s_counts, p_counts)) {
                res.push_back(i - k + 1);
            }
        }

        return res;
    }
};