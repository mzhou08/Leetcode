#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res = {};
        vector<int> toMerge = newInterval;
        bool merged = false;
        
        for (int i = 0; i < intervals.size(); i++) {
            if (
                intervals[i][0] <= newInterval[0]
                && intervals[i][1] >= newInterval[1]
            ) {//intervals[i] starts before, ends after
                res.push_back(intervals[i]);
                merged = true;
            } else if (
                intervals[i][0] >= newInterval[0]
                && intervals[i][1] >= newInterval[1]
                && intervals[i][0] <= newInterval[1]
            ) {//intervals[i] starts after, ends after
                toMerge[1] = intervals[i][1];
                res.push_back(toMerge);
                merged = true; // no more overlaps possible
            } else if (
                intervals[i][0] <= newInterval[0]
                && intervals[i][1] <= newInterval[1]
                && intervals[i][1] >= newInterval[0]
            ) {//intervals[i] starts before, ends before
                toMerge[0] = intervals[i][0];
            } else if (
                intervals[i][0] >= newInterval[0]
                && intervals[i][1] <= newInterval[1]
            ) {//intervals[i] starts after, ends before
                toMerge[1] = newInterval[1];
            } else if (intervals[i][0] > newInterval[1] && not merged ){
                res.push_back(toMerge);
                res.push_back(intervals[i]);
                merged = true;
            } else {
                res.push_back(intervals[i]);
            }
        }
        
        if (intervals.size() == 0 || (not merged)) {
            res.push_back(toMerge);
        }
        
        return res;
    }
};