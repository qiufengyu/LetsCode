#include "../header.h"

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size(), res = s.size();
        vector<int> count1(n+1, 0), count0(n+1, 0);
        for (int i = 1, j = n - 1; j >= 0; ++i, --j) {
            count1[i] += count1[i - 1] + (s[i-1] == '0' ? 0 : 1);
            count0[j] += count0[j + 1] + (s[j] == '0' ? 1 : 0);
        }
        for (int i = 0; i <= n; ++i) {
            res = min(res, count1[i] + count0[i]);
        }
        return res;
    }
};