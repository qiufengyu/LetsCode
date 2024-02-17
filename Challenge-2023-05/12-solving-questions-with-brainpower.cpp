#include "../header.h"

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            auto q = questions[i];
            int nextQuestion = min(q[1] + i + 1, n);
            dp[i] = max(q[0] + dp[nextQuestion], dp[i+1]);
        }
        return dp[0];
    }
};