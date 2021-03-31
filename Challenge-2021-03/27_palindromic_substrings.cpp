#include "../header.h"

class Solution {
public:
    int countSubstrings(string s) {
        int dp[1001][1001];
        bool isPalindromic[1001][1001];
        int sz = s.length();
        for (int i = 0; i < sz; ++i) {
          dp[i][i] = 1;
          isPalindromic[i][i] = true;
          for (int j = i + 1; j < sz; ++j) {
            dp[i][j] = 0;
            isPalindromic[i][j] = false;
          }
        }
        for (int i = 0; i < sz - 1; ++i) {
          dp[i][i+1] = 2;
          if (s[i] == s[i+1]) {
            isPalindromic[i][i+1] = true;
            ++dp[i][i+1];
          }
        }
        for (int i = 0; i < sz; ++i) {
          for (int j = 0; j < sz; ++j) {
            cout << dp[i][j] << " ";
          }
          cout << endl;
        }
        for (int l = 2; l < sz; ++l) {
          for (int i = 0; i < sz - l; ++i) {
            int j = l + i;
            dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
            if (s[i] == s[j] && isPalindromic[i+1][j-1]) {
              isPalindromic[i][j] = true;
              ++dp[i][j];
            }
          }
        }
        for (int i = 0; i < sz; ++i) {
          for (int j = 0; j < sz; ++j) {
            cout << dp[i][j] << " ";
          }
          cout << endl;
        }
        return dp[0][sz-1];
    }
};

int main() {
  string s {"abc"};
  cout << Solution().countSubstrings(s) << endl;
  return 0;
}