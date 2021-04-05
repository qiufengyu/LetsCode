#include "../header.h"

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
      for (auto const& str: strs) {
        int zeroes = 0, ones = 0;
        for (auto c: str) {
          if (c == '0') ++zeroes;
          else ++ones;
        }
        for (int i = m; i >= zeroes; --i) {
          for (int j = n; j >= ones; --j) {
            dp[i][j] = max(dp[i][j], dp[i-zeroes][j-ones] + 1);
          }
        }
      }
      return dp[m][n];
    }
};