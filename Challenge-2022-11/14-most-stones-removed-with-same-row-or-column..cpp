#include "../header.h"

class Solution {
    unordered_map<int, int> m;
    int islands = 0;
public:
    int find(int x) {
        if (m.count(x) == 0) {
            m[x] = x;
            ++islands;
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
            --islands;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        for (int i = 0; i < stones.size(); ++i) {
            u(stones[i][0], ~stones[i][1]);
        }
        return stones.size() - islands;
    }
};