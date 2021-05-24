#include "../header.h"

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) -> bool {
          return a.size() < b.size();
        });
        unordered_map<string, int> m;
        int n = words.size();
        vector<int> dp(n, 1);
        int mx = 1;
        for (int i = 0; i < n; ++i) {
          m[words[i]] = i;
          if (words[i].size() > 1) {
            for (int j = 0; j < words[i].size(); ++j) {
              string temp = words[i].substr(0, j) + words[i].substr(j+1, words[i].size() - j);
              if (m.count(temp) > 0) {
                dp[i] = max(dp[i], dp[m[temp]] + 1);
              }
            }
          }
          mx = max(dp[i], mx);
        }
        return mx;
    }
};