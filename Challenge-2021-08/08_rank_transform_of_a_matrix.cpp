#include "../header.h"

class UF {
    vector<int> v;
public:
    UF(int n): v(n, -1) {}
    int f(int x) {
        if (v[x] == -1) {
            return x;
        } else {
            v[x] = f(v[x]);
            return v[x];
        }
    }
    void u(int x, int y) {
        x = f(x);
        y = f(y);
        if (x != y) {
            v[x] = y;
        }
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        map<int, vector<pair<int, int>>> mp; // val -> positions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mp[matrix[i][j]].push_back({j, i});
            }
        }
        vector<int> rx(n), ry(m);
        for (const auto& [val, ps]: mp) {
            UF uf(m + n);
            vector<vector<pair<int, int>>> cc(m + n);
            for (const auto& [x, y]: ps) {
                uf.u(x, y + n);
            }
            for (const auto& [x, y]: ps) {
                cc[uf.f(x)].push_back({x, y});
            }
            for (const auto& ps: cc) {
                int r = 1;
                for (const auto& [x, y]: ps) {
                    r = max(r, max(rx[x], ry[y]) + 1);
                }
                for (const auto& [x, y]: ps) {
                    rx[x] = ry[y] = res[y][x] = r;
                }
            }
        }
        return res;
    }
};
