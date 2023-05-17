#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
private:
    double dist(vi point) {
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }

public:
    vvi kClosest(vvi& points, int k) {
        if (points.size() <= k) return points;

        int pivot = rand() % points.size();

        vvi L; vvi R;
        
        for (int i = 0; i < points.size(); i++) {
            if (dist(points[i]) <= dist(points[pivot])) {
                L.push_back(points[i]);
            } else {
                R.push_back(points[i]);
            }
        }

        if (L.size() >= k) {
            return kClosest(L, k);
        } else {
            vvi right = kClosest(R, k - L.size());
            vvi res = right; res.reserve(right.size() + L.size());
            res.insert(res.end(), L.begin(), L.end());
            return res;
        }
    }
};