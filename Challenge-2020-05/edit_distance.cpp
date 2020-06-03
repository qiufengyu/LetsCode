#include "header.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t l1 = word1.length() + 1;
        size_t l2 = word2.length() + 1;
        vector<vector<int>> dp(l1, vector<int>(l2, 0));
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
                }
            }
        }
        return dp[l1-1][l2-1];
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << Solution().minDistance(s1, s2) << endl;
    return 0;
}