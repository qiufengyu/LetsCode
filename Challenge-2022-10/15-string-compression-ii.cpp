#include "../header.h"

const int N = 127;

inline int digits(int x) {
    return x == 1 ? 0 : (x < 10 ? 1 : (x < 100 ? 2 : 3));
}

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int sz = s.size();
        return solve(dp, s, sz, 0, k);
    }

    int solve(vector<vector<int>>& dp, string const& s, int const sz, int left, int k) {
        if (k < 0) {
            return N;
        }
        if (left >= sz || sz - left <= k) {
            return 0;
        }
        int& res = dp[left][k];
        if (res != -1) {
            return res;
        }
        res = N;
        int cnt[26] = {0};
        for (int j = left, most = 0; j < sz; ++j) {
            most = max(most, ++cnt[s[j] - 'a']);
            res = min(res, 1 + digits(most) + solve(dp, s, sz, j + 1, k - (j - left + 1 - most)));
        }
        return res;
    }
};