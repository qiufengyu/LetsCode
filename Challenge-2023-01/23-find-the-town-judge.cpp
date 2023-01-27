#include "../header.h"

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> t1(n+1, 0), t2(n+1, 0);
        for (auto const& t: trust) {
            ++t1[t[0]];
            ++t2[t[1]];
        }
        for (int i = 1; i <= n; ++i) {
            if (t1[i] == 0 && t2[i] == (n-1)) {
                return i;
            }
        }
        return -1;
    }
};