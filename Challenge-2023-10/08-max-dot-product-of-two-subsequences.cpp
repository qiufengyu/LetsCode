#include "../header.h"

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
        dp[0][0] = nums1[0] * nums2[0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = max(dp[i-1][0], nums2[0] * nums1[i]);
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = max(dp[0][i-1], nums1[0] * nums2[i]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int tmp = nums1[i] * nums2[j];                
                dp[i][j] = max(max(max(dp[i-1][j-1] + max(tmp, 0), dp[i-1][j]), dp[i][j-1]), tmp);
            }
        }
        print_vector<int>(dp);
        return dp[m-1][n-1];
    }
};

int main() {
    vector<int> nums1 {-3,-8,3,-10,1,3,9};
    vector<int> nums2 {9,2,3,7,-9,1,-8,5,-1,-1};
    cout << Solution().maxDotProduct(nums1, nums2) << endl;
}