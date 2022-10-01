#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vvi kClosest(vvi& points, int k) {
        if (points.size() <= 1) {
            return points;
        }
        
        
        int half = (points.size() / 2);
        vvi left = vvi(points.begin(), points.begin() + half);
        vvi right = vvi(points.begin() + half, points.end());
        
        
        vvi leftK = kClosest(left, k);
        vvi rightK = kClosest(right, k);
        
        vvi res = vvi(0, vi(0));
        
        for (int i = 0; i < k; i++) {
            bool leftEmpty = (leftK.size() == 0);
            bool rightEmpty = (rightK.size() == 0);
            
            if (leftEmpty && rightEmpty) {
                return res;
            } else if (leftEmpty) {
                res.push_back(rightK[0]);
                rightK.erase(rightK.begin());
            } else if (rightEmpty) {
                res.push_back(leftK[0]);
                leftK.erase(leftK.begin());
            } else {
                int leftDist = (
                    pow(leftK[0][0], 2) + pow(leftK[0][1], 2)
                );
                int rightDist = (
                    pow(rightK[0][0], 2) + pow(rightK[0][1], 2)
                );
                if (leftDist <= rightDist) {
                    res.push_back(leftK[0]);
                    leftK.erase(leftK.begin());
                } else {
                    res.push_back(rightK[0]);
                    rightK.erase(rightK.begin());
                }
            }
        }
        
        return res;
    }
};