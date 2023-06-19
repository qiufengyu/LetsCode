#include "../header.h"

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        sort(arr2.begin(), arr2.end());
        int res = helper(arr1, arr2, 0, 0, n1, n2, -1, dp);
        if (res > n1) {
            return -1;
        }
        return res;
    }

    int helper(vector<int>& arr1, vector<int>& arr2, int i, int j, const int n1, const int n2, int p, vector<vector<int>>& dp) {
        if (i == n1) {
            return 0;
        }
        j = upper_bound(arr2.begin() + j, arr2.end(), p) - arr2.begin();
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (j == n2 && arr1[i] <= p) { // cannot make arr1 strictly increasing
            return n1 + 1;
        }
        int take = n1 + 1, notTake = n1 + 1;
        if (j != n2) {
            take = helper(arr1, arr2, i + 1, j + 1, n1, n2, arr2[j], dp) + 1;
        }
        if (arr1[i] > p) {
            notTake = helper(arr1, arr2, i + 1, j, n1, n2, arr1[i], dp);
        }
        dp[i][j] = min(take, notTake);
        return dp[i][j];
    }
};