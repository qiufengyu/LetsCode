#include "../header.h"

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> conn(n, 0);
        for (auto const& r: roads) {
            conn[r[0]]++;
            conn[r[1]]++;
        }
        sort(conn.begin(), conn.end());
        long long res = 0LL;
        for (int i = 0; i < n; i++) {
            res += (long long)(i + 1) * conn[i];
        }
        return res;
    }
};