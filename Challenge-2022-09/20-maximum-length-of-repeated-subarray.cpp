#include "../header.h"

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        int res = 0;
        for (int i = l1 - 1; i >= 0; --i) {
            for (int j = l2 - 1; j >= 0; --j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};