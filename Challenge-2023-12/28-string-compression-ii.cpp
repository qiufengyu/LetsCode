#include "../header.h"

inline int getLength(int count) {
    if (count == 1) {
        return 1;
    }else if (count < 10) {
        return 2;
    } else if (count < 100) {
        return 3;
    }
    return 4;
}

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                // delete current char when it is still possible
                dp[i][j] = j > 0 ? dp[i+1][j-1] : INT_MAX;
                int del = j, count = 0;
                for (int end = i; end < n && del >= 0; end++) {
                    if (s[end] == s[i]) {
                        count++;
                        dp[i][j] = min(dp[i][j], getLength(count) + dp[end+1][del]);
                    } else {
                        del--;
                    }
                }
            }
        }
        return dp[0][k];
    }
};