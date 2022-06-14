#include "../header.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        print_vector<int>(dp);
        int lcs = dp[n1][n2];
        return n1 + n2 - lcs * 2;        
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << Solution().minDistance(s1, s2) << endl;
    return 0;
}