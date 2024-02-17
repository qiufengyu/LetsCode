#include "../header.h"

class DSU {
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n): parent(n, 0), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int f(int x) {
        if (parent[x] != x) {
            parent[x] = f(parent[x]);
        }
        return parent[x];
    }

    bool u(int x, int y) {
        int xx = f(x), yy = f(y);
        if (xx != yy) {
            if (rank[xx] < rank[yy]) {
                parent[xx] = yy;
            } else if (rank[xx] > rank[yy]) {
                parent[yy] = xx;
            } else {
                parent[yy] = xx;
                rank[xx]++;
            }
            return true;
        }
        return false;
    }

    bool connected(int x, int y) {
        return f(x) == f(y);
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[0] > b[0];
        });
        DSU da(n+1), db(n+1);
        int r = 0, alice = 0, bob = 0;
        // should start from type 3
        for (auto const& e: edges) {
            if (e[0] == 3) {
                if (da.u(e[1], e[2])) {
                    db.u(e[1], e[2]);
                    alice++;
                    bob++;
                } else {
                    r++;
                }
            } else if (e[0] == 1) {
                if (da.u(e[1], e[2])) {
                    alice++;
                } else {
                    r++;
                }
            } else {
                if (db.u(e[1], e[2])) {
                    bob++;
                } else {
                    r++;
                }
            }
        }
        if (alice == n - 1 && bob == n - 1) {
            return r;
        }
        return -1;
    }
};