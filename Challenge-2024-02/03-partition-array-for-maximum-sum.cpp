#include "../header.h"

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        for (int i = 1; i < n; i++) {
            int mx = arr[i];
            for (int j = 0; j < k && i - j >= 0; j++) {
                dp[i] = max((i - j >= 1 ? dp[i-j-1] : 0) + mx * (j + 1), dp[i]);
                mx = max(mx, (i - j >= 1 ? arr[i-j-1] : 0));
            }
        }
        print_vector<int>(dp);
        return dp[n-1];
    }
};

int main() {
    vector<int> arr {1,15,7,9,2,5,10};
    int k = 3;
    int res = Solution().maxSumAfterPartitioning(arr, k);
    cout << res << endl;
    return 0;
}