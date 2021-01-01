#include "../header.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
      int n = s.length();
      vector<vector<bool>> dp(n, vector<bool>(n, false));
      // for (int i = 0; i < n; i++) dp[i][i] = true;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
          // dp[j][j+i]
          if (s[j] == s[j+i] && (i <= 2 || dp[j+1][j+i-1])) {
            dp[j][j+i] = true;
          }
        }
      }
      print_vector<bool>(dp);
      vector<vector<string>> res;
      vector<string> current;
      helper(s, 0, dp, current, res);
      return res;        
    }

    void helper(string s, int start, vector<vector<bool>>& dp, vector<string>& current, vector<vector<string>>& res) {
      if (start == s.size()) {
        res.push_back(current);
        return;
      }
      for (int i = start; i < s.size(); i++) {
        if (!dp[start][i]) continue;
        current.push_back(s.substr(start, i - start + 1));
        helper(s, i + 1, dp, current, res);
        current.pop_back();
      }
    }
};

int main() {
  string s {"abbab"};
  Solution().partition(s);
  return 0;
}