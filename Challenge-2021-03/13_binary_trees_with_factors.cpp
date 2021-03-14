#include "../header.h"

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int M = 1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;
        for (int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0 && dp.count(arr[i] / arr[j])) {
                    dp[arr[i]] += (dp[arr[j]] * dp[arr[i] / arr[j]]) % M;
                }
            }
        }
        long ans = 0L;
        for (const auto& kv: dp) {
            ans += kv.second;
        }
        return ans % M;
    }
};