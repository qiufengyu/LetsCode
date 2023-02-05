#include "../header.h"

typedef pair<int, int> PII;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<PII> v;
        int n = scores.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end());
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            auto p = v[i];
            int a = p.first, s = p.second;
            dp[i] = s;
            for (int j = 0; j < i; ++j) {
                if (v[j].second <= s) {
                    dp[i] = max(dp[i], dp[j] + s);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};