#include "../header.h"

class Solution {
public:
    vector<int> beautifulArray(int n) {
        unordered_map<int, vector<int>> m;
        return helper(m, n);
    }

    vector<int> helper(unordered_map<int, vector<int>>& m, int n) {
        int i = 0;
        vector<int> v(n, 0);
        if (m.count(n)) {
            return m[n];
        }
        if (n != 1) {
            for (auto x: helper(m, (n+1) / 2)) {
                v[i] = 2 * x - 1;
                i++;
            }
            for (auto x: helper(m, n / 2)) {
                v[i] = 2 * x;
                i++;
            }
        }
        else {
            v[0] = 1;
        }
        m[n] = v;
        return v;
    }
};