#include "../header.h"

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        int n = target.length();
        int sn = stamp.length();
        vector<bool> stamped(n, false);
        int count = 0;
        while (count < n) {
          bool found = false;
          for (int i = 0; i <= n - sn; ++i) {
            if (stamped[i]) {
              continue;
            }
            int l = unStamp(stamp, target, i);
            if (l == 0) {
              continue;
            }
            stamped[i] = true;
            count += l;
            res.push_back(i);
            found = true;
          }
          if (!found) {
            return {};
          }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int unStamp(const string& stamp, string& target, int i) {
      int l = stamp.length();
      for (int j = 0; j < stamp.length(); ++j) {
        if (target[i + j] == '*') {
          --l;
        } else if (target[i + j] != stamp[j]) {
          return 0;
        }
      }
      if (l != 0) {
        fill(target.begin() + i, target.begin() + i + stamp.length(), '*');
      }
      return l;
    }
};