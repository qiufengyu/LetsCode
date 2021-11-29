#include "../header.h"

class Solution {
    vector<int> m;
    void unionSet(int x, int y) {
        x = findSet(x);
        y = findSet(y);
        if (x != y) {
            m[y] = x;
        }
    }
    int findSet(int x) {
        if (x == m[x]) {
            return x;
        }
        m[x] = findSet(m[x]);
        return m[x];
    }
public:
    Solution(): m(100001, 0) {}
    int largestComponentSize(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        for (int i = 0; i <= mx; ++i) {
            m[i] = i;
        }
        for (int x: nums) {
            int s = sqrt(x);
            for (int i = 2; i <= s; ++i) {
                if (x % i == 0) {
                    unionSet(x, i);
                    unionSet(x, x / i);
                }
            }
        }
        unordered_map<int, int> count;
        int res = 0;
        for (int x: nums) {
            int t = ++count[findSet(x)];
            res = max(res, t);
        }
        return res;
    }
};