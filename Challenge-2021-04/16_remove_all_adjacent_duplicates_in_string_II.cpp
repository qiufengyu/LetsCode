#include "../header.h"

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int> m;
        if (s.empty()) {
          return s;
        }
        m[0] = 1;
        for (int i = 1; i < s.size(); ++i) {
          if (s[i] != s[i-1]) {
            m[i] = 1;
          } else {
            m[i] = m[i-1] + 1;
            if (m[i] == k) {
              s.erase(i-k+1, k);
              i = i - k;
            }
          }
        }
        return s;
    }
};