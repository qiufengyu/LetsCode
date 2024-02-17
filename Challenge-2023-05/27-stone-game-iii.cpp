#include "../header.h"

class Solution {
public:
    int play(vector<int>& stoneValue, vector<int>& dp, int i, const int n) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != INT_MAX) {
            return dp[i];
        }        
        int take1 = stoneValue[i] - play(stoneValue, dp, i+1, n);
        int take2 = INT_MIN, take3 = INT_MIN;
        if (i + 1 < n) {
            take2 = stoneValue[i] + stoneValue[i+1] - play(stoneValue, dp, i+2, n);
        }
        if (i + 2 < n) {
            take3 = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - play(stoneValue, dp, i+3, n);
        }
        dp[i] = max(take1, max(take2, take3));
        return dp[i];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MAX);
        int alice = play(stoneValue, dp, 0, n);
        if (alice > 0) {
            return "Alice";
        } else if (alice < 0) {
            return "Bob";
        }
        return "Tie";
    }
};