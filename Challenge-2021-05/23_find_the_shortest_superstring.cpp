#include "../header.h"

class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            g[i][j] = appendIJ(words[i], words[j]);
            g[j][i] = appendIJ(words[j], words[i]);
          }
        }
        vector<vector<int>> dp(1<<n, vector<int>(n, INT_MAX));
        vector<vector<int>> parent(1<<n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
          dp[1 << i][i] = words[i].length();
        }
        for (int s = 1; s < (1 << n); ++s) {
          for (int i = 0; i < n; ++i) {
            if (!(s & (1 << i))) {
              continue;
            }
            int prev = s - (1 << i);
            for (int j = 0; j < n; ++j) {
              if (dp[prev][j] + g[j][i] < dp[s][i]) {
                dp[s][i] = dp[prev][j] + g[j][i];
                parent[s][i] = j;
              }
            }
          }
        }
        vector<int> mdp = dp.back();
        vector<int>::iterator it = min_element(mdp.begin(), mdp.end());
        int current = it - mdp.begin();
        int s = (1 << n) - 1;
        string ans;
        while (s) {
          int prev = parent[s][current];
          if (prev < 0) {
            ans = words[current] + ans;
          } else {
            ans = words[current].substr(words[current].length() - g[prev][current]) + ans;
          }
          s &= ~(1 << current);
          current = prev;
        }
        return ans;
    }

    int appendIJ(const string& a, const string& b) {
      int al = a.length(), bl = b.length();
      int d = bl;
      for (int k = 1; k < min(al, bl); ++k) {
        if (a.substr(al-k) == b.substr(0, k)) {
          d = bl - k;
        }
        return d;
      }
    }
};