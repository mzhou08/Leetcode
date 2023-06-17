class Solution {
public:
    int areaHelper(vector<int>& heights, int lo, int hi) {
        if (lo > hi) return 0;
        
        int shortestHeight = INT_MAX;
        int shortestIdx = -1;

        for (int i = lo; i <= hi; i++) {
            if (heights[i] < shortestHeight) {
                shortestHeight = heights[i];
                shortestIdx = i;
            }
        }

        return max(
            shortestHeight * (hi - lo + 1),
            max(
                areaHelper(heights, lo, shortestIdx - 1),
                areaHelper(heights, shortestIdx + 1, hi)
            )
        );
    }

    int largestRectangleArea(vector<int>& heights) {
        /*
            O(n^2) brute force:
            Take all towers and the paths between them.
            Calculate areas for each, and take the max.


            More clever approach:
            Divide & Conquer.

            For each array segment, store:
                height of shortest bar

            
            At each joining of L and R, the max area is
                len of array * shortest bar
                largest area right of shortest bar
                largest area left of shortest bar


            So we split on shortest bar.
        */
        return areaHelper(heights, 0, heights.size() - 1);
    }
};