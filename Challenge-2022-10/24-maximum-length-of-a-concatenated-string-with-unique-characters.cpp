#include "../header.h"

int countBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> dp = {0};
        int res = 0;
        for (auto const& s: arr) {
            int t = 0;
            for (char c: s) {
                t = t | (1 << (c - 'a'));
            }
            int n = countBits(t);
            if (countBits(t) < s.size()) {
                continue;
            }
            for (int i = dp.size() - 1; i >= 0; --i) {
                int di = dp[i];
                if ((di & t) == 0) {
                    dp.push_back(di | t);
                    res = max(res, (int)(countBits(di) + s.size()));
                }
            }
        }
        return res;
    }
};