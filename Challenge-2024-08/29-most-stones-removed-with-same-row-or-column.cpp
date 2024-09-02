#include "../header.h"


class Solution {
    unordered_map<int, int> m;
    int island = 0;
public:
    int find(int x) {
        if (m.count(x) == 0) {
            m[x] = x;
            island++;
        }
        if (m[x] != x) {
            m[x] = find(m[x]);
        }
        return m[x];
    }
    void u(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            m[x] = y;
            island--;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            u(stones[i][0], ~stones[i][1]);
        }
        return n - island;
    }
};