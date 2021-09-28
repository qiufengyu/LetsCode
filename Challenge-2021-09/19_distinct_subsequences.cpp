#include "../header.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        int ss = s.size(), ts = t.size();
        vector<vector<unsigned>> dp(ts + 1, vector<unsigned>(ss + 1, 0));
        for (int i = 0; i <= ss; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= ts; ++i) {
            for (int j = 1; j <= ss; ++j) {
                dp[i][j] = dp[i][j-1] + ((s[j-1] == t[i-1]) ? dp[i-1][j-1] : 0L);
            }
        }
        return dp[ts][ss];        
    }
};

int main() {
    cout << Solution().numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}