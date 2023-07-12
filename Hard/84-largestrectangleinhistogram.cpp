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

            But this O(nlogn) solution is too slow
        */
        // return areaHelper(heights, 0, heights.size() - 1);


        /*
            Need O(n) solution.

            Maintain a stack of idx.

            So let's traverse the heights from L to R.
            At each new step, if it is a drop, then we
            look at all previous heights that are at least as tall.

            Pop off all pairs with height at least curr,
            and consider curr * (1 + sum(widths)) as potential max.

            Else if the heights is increasing, then we consider the
            single bar a potential max, as well as
            previous rectangle + 1 width.
        */

        vector<int> stack = {-1};

        int max_area = 0;

        for (int i = 0; i < heights.size(); i++) {
            // if there is a decrease in height
            while (
                stack.back() != -1 &&
                heights[stack.back()] >= heights[i]
            ) {
                // pop all entries on the stack taller than i
                // why? all rectangles going through i
                // will now be limited by i at least.
                int limitingHeight = heights[stack.back()];
                stack.pop_back();

                int left = stack.back();

                int right = i;

                max_area = max(
                    max_area,
                    limitingHeight * (right - left - 1)
                );
            }

            stack.push_back(i);
        }

        int n = heights.size();

        // done with creating the stack
        while (stack.back() != -1) {
            int limitingHeight = heights[stack.back()];
            stack.pop_back();

            int left = stack.back();

            max_area = max(
                max_area,
                limitingHeight * (n - left - 1)
            );
        }


        return max_area;
    }
};