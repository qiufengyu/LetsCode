#include "../header.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        bool dp[1001][1001];
        int maxLength = 1;
        int maxStart = 0;
        for (int i = 0; i < length; i++) {
          dp[i][i] = true;
          if (i < length - 1 ) {
            dp[i][i+1] = (s[i] == s[i+1]);
            if (dp[i][i+1]) {
              maxLength = 2;
              maxStart = i;
            }
          }
          for (int j = i+2; j < length; j++) {
            dp[i][j] = false;
          }
        }
        for (int l = 2; l <= length; l++) {
          for (int i = 0; i + l < length; i++) {
            // calc dp[i][i+l]
            dp[i][i+l] = dp[i+1][i+l-1] && (s[i] == s[i+l]);
            if (dp[i][i+l]) {
              maxStart = i;
              maxLength = l + 1;
            }
          }
        }
        for(int i = 0; i<length; i++) {
            for(int j = 0; j<length; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return s.substr(maxStart, maxLength);
    }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().longestPalindrome(s) << endl;
  return 0;

}