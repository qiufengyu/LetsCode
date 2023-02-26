#include "../header.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));;
        for (int i = 0; i <= l1; ++i) {
            for (int j = 0; j <= l2; ++j) {
                if (j == 0) {
                    dp[i][j] = i;
                } else if (i == 0) {
                    dp[i][j] = j;
                } else {
                    if (word1[i-1] == word2[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    }
                }
            }
        }
        return dp[l1][l2];
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << Solution().minDistance(s1, s2) << endl;
    return 0;
}