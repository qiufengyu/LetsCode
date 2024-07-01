#include "../header.h"

class DSU {
    vector<int> parent;
    int edges;
public:
    DSU(int n): parent(n+1), edges{0} {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    int merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) {
            return 1;
        }
        parent[px] = py;
        edges++;
        return 0;
    }

    int getEdges() const {
        return edges;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int res = 0;
        DSU alice{n}, bob{n};
        for (auto const& edge: edges) {
            if (edge[0] != 3) {
                continue;
            }
            res += alice.merge(edge[1], edge[2]);
            bob.merge(edge[1], edge[2]);
        }
        for (auto const& edge: edges) {
            if (edge[0] == 3) {
                continue;
            }
            DSU &d = edge[0] == 1 ? alice : bob;
            res += d.merge(edge[1], edge[2]);
        }
        if (alice.getEdges() == bob.getEdges() && alice.getEdges() == n - 1) {
            return res;
        }
        return -1;
    }
};