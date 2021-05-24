#include "../header.h"

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        map<char, char> m1, m2;
        int len = pattern.size();
        for (auto &word: words) {
          m1.clear();
          m2.clear();
          int i = 0;
          for (i = 0; i < len; ++i) {
            char c1 = word[i], c2 = pattern[i];
            if (!m1.count(c1)) {
              m1[c1] = c2;
            }
            if (!m2.count(c2)) {
              m2[c2] = c1;
            }
            if (m1[c1] != c2 || m2[c2] != c1) {
              break;
            }
          }
          if (i == len) {
            res.push_back(word);
          }
        }
        return res;
    }
};