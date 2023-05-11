class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int *ransomCounts = (int*) calloc(sizeof(int), 26);
        int *magazineCounts = (int*) calloc(sizeof(int), 26);

        for (int i = 0; i < ransomNote.size(); i++) {
            int ord = int(ransomNote[i]) - int('a');
            ransomCounts[ord]++;
        }

        for (int i = 0; i < magazine.size(); i++) {
            int ord = int(magazine[i]) - int('a');
            magazineCounts[ord]++;
        }

        for (int i = 0; i < 26; i++) {
            cout << ransomCounts[i] << " " << magazineCounts[i] << "\n";
            if (ransomCounts[i] > magazineCounts[i]) {
                free(ransomCounts);
                free(magazineCounts);
                return false;
            }
        }

        free(ransomCounts);
        free(magazineCounts);

        return true;
    }
};