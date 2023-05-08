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
        while (parent[x] != x) {
            x = parent[x];
        }
        return parent[x];
    }

    void u(int x, int y) {
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
        }
    }

    bool connected(int x, int y) {
        return f(x) == f(y);
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int l = queries.size();
        vector<bool> res(l, false);
        for (int i = 0; i < l; ++i) {
            queries[i].push_back(i);
        }
        // the dsu will be added more by increasing the limit in the queries
        sort(queries.begin(), queries.end(), [](vector<int> const& q1, vector<int> const& q2) -> bool {
            return q1[2] < q2[2];
        });
        sort(edgeList.begin(), edgeList.end(), [](vector<int> const& e1, vector<int> const& e2) -> bool {
            return e1[2] < e2[2];
        });
        DSU dsu(n);
        int i = 0;
        for (auto const& q: queries) {
            int u = q[0], v = q[1], lmt = q[2], qid = q[3];
            while (i < edgeList.size() && edgeList[i][2] < lmt) {
                dsu.u(edgeList[i][0], edgeList[i][1]);
                ++i;
            }
            res[qid] = dsu.connected(u, v);
        }
        return res;
    }
};