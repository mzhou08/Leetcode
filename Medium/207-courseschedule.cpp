#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<int> qi;

class Solution {
public:
    bool canFinish(int numCourses, vvi& prerequisites) {
        vvi prereqs(numCourses, vi(0));
        vi num_prereqs(numCourses, 0);
        
        for (vi edge: prerequisites) {
            if (edge[0] == edge[1]) return false;
            
            prereqs[edge[1]].push_back(edge[0]);
            num_prereqs[edge[0]]++;
            // [0, 1] means edge from 1 -> 0
        }

        int edges_remaining = prerequisites.size();
        
        vector<bool> visited(numCourses, false);

        qi no_prereqs;

        for (int i = 0; i < numCourses; i++) {
            if (num_prereqs[i] == 0 && !visited[i]) {
                no_prereqs.push(i);
            }
        }

        while (!no_prereqs.empty()) {
            int i = no_prereqs.front();
            no_prereqs.pop();

            visited[i] = true;

            for (int j: prereqs[i]) {
                if (!visited[j]) {
                    num_prereqs[j]--;
                    edges_remaining--;
                    if (num_prereqs[j] == 0) no_prereqs.push(j);
                }
            }
        }

        return edges_remaining == 0;
    }
};