#include "../header.h"

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int res = 1; // arr.size() >= 1
        int inc = 1, dec = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i-1]) {
                inc = dec + 1;
                dec = 1;
            }
            else if (arr[i] < arr[i-1]) {
                dec = inc + 1;
                inc = 1;
            }
            else {
                dec = 1;
                inc = 1;
            }
            res = max(res, max(dec, inc));
        }
        return res;
    }
    // Time Limit Exceeded
    int maxTurbulenceSize2(vector<int>& arr) {
        int n = arr.size();
        int res = 1; // arr.size() >= 1
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            dp[i][i] = 1;
            if (arr[i] != arr[i-1]) {
                dp[i-1][i] = 2;
                res = 2;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 2; j < n; ++j) {
                if (dp[i][j-1] != 0) {
                    if ((arr[j-1] < arr[j-2] && arr[j-1] < arr[j]) || (arr[j-1] > arr[j-2] && arr[j-1] > arr[j])){
                        dp[i][j] = dp[i][j-1] + 1;
                        res = max(res, dp[i][j]);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> arr = stringToIntegerVector(s);
    cout << Solution().maxTurbulenceSize(arr) << endl;
    return 0;
}