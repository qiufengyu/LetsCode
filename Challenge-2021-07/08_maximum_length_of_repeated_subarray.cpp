#include "../header.h"

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        vector<vector<int>> dp(sz1+1, vector<int>(sz2+1, 0));
        int res = 0;
        for (int i = sz1 - 1; i >=0; --i) {
            for (int j = sz2 - 1; j >= 0; --j) {
                dp[i][j] = nums1[i] == nums2[j] ? (1 + dp[i+1][j+1]) : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};