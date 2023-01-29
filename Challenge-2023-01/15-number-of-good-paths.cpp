#include "../header.h"

class Solution {
    vector<int> uf;
public:
    // if not update with latest "parent", it will always find the path again and again => cause TLE
    int f(int n) {
        if (uf[n] == n) {
            return n;
        }
        uf[n] = f(uf[n]);
        return uf[n];
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        uf.resize(n);
        for (int i = 0; i < n; ++i) {
            uf[i] = i;
        }
        int res = n;
        vector<int> count(n, 1);
        sort(edges.begin(), edges.end(), [&](const vector<int>& x, const vector<int>& y) {
           return max(vals[x[0]], vals[x[1]]) < max(vals[y[0]], vals[y[1]]);
        });
        for (auto const& edge: edges) {
            int x = edge[0], y = edge[1];
            x = f(x);
            y = f(y);
            if (vals[x] == vals[y]) {
                res += count[x] * count[y];
                uf[x] = y;
                count[y] += count[x];
            } else if (vals[x] > vals[y]) {
                uf[y] = x;
            } else {
                uf[x] = y;
            }
        }
        return res;
    }
};

int main() {
    vector<int> vals {1,3,2,1,3};
    vector<vector<int>> edges {{0,1},{0,2},{2,3},{2,4}};
    int res = Solution().numberOfGoodPaths(vals, edges);
    return 0;
}