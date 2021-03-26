#include "../header.h"

constexpr int allSize = 26 * sizeof(int);

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int chars[26];
        memset(chars, 0, allSize);
        for (auto &s: B) {
          int charsB[26];
          memset(charsB, 0, allSize);
          for (auto c: s) {
            ++charsB[c - 'a'];
          }
          for (int i = 0; i < 26; ++i) {
            chars[i] = max(chars[i], charsB[i]);
          }
        }
        vector<string> res;
        for (auto &s: A) {
          int charsA[26];
          memset(charsA, 0, allSize);
          for (auto c: s) {
            ++charsA[c - 'a'];
          }
          bool yes = true;
          for (int i = 0; i < 26; ++i) {
            if (charsA[i] < chars[i]) {
              yes = false;
              break;
            }
          }
          if (yes) {
            res.push_back(s);
          }
        }
        return res;
    }
};