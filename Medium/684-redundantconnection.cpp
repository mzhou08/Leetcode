#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class UnionFindDS {
public:
    vi parents;

    UnionFindDS(int n) {
        parents = vi(n);

        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]); // update parent to OG ancestor
        }

        return parents[x];
    }

    bool union_chains(int x, int y) {
        if (find(x) == find(y)) { // not parents[x], because might not the the OG ancestor
            return false;
        }

        parents[ find(x) ] = parents[y];
        return true;
    }
};

class Solution {
public:
    vi findRedundantConnection(vvi& edges) {
        
        int n = edges.size();

        UnionFindDS ufds = UnionFindDS(n);

        for (vi edge: edges) {
            int u = edge[0]; int v = edge[1];

            if (!ufds.union_chains(u-1, v-1)) return edge;
        }
        
        return vi(0); // error
    }
};