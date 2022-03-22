#include "../header.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size(), l2 = text2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        int res = 0;
        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j) {
                if (text1[i] == text2[j]) {
                    dp[i+1][j+1] = 1 + dp[i][j];
                    res = max(res, dp[i+1][j+1]);
                } else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return res;
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << Solution().longestCommonSubsequence(s1, s2) << endl;
    return 0;
}