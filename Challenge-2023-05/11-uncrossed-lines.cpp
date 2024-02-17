#include "../header.h"

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = nums1[0] == nums2[0];
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0];
            if (nums1[i] == nums2[0]) {
                dp[i][0] = 1;
            }
        }
        for (int i = 1; i < n; ++i) {
            dp[0][i] = dp[0][i-1];
            if (nums2[i] == nums1[0]) {
                dp[0][i] =1, dp[0][i-1];
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    vector<int> n1{1,4,2}, n2{1,2,4};
    auto res = Solution().maxUncrossedLines(n1, n2);
    cout << res << endl;
    return 0;
}