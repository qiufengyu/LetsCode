#include "../header.h"

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n+5, vector<int>(k+1, -1));
        return helper(events, k, dp, 0);
    }

    int search(vector<vector<int>>& events, int start, int endTime) {
        int l = start, h = events.size()-1, index = -1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (events[m][0] > endTime) {
                index = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return index;
    }

    int helper(vector<vector<int>>& events, int k, vector<vector<int>>& dp, int index) {
        if (index >= events.size() || k == 0 || index == -1) {
            return 0;
        }
        if (dp[index][k] != -1) {
            return dp[index][k];
        }
        int nxt = search(events, index + 1, events[index][1]);
        int c1 = events[index][2] + helper(events, k - 1, dp, nxt);
        int c2 = helper(events, k, dp, index + 1);
        dp[index][k] = max(c1, c2);
        return dp[index][k];
    }
};