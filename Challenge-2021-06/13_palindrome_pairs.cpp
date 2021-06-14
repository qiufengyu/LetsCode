#include "../header.h"

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
      vector<vector<int>> res;
      unordered_map<string, int> m;
      set<int> s;
      for (int i = 0; i < words.size(); ++i) {
        m[words[i]] = i;
        s.insert(words[i].size());
      }
      for (int i = 0; i < words.size(); ++i) {
        string st = words[i];
        int l = st.size();
        reverse(st.begin(), st.end());
        if (m.count(st) && m[st] != i) {
          res.push_back({i, m[st]});
        }
        auto lit = s.find(l);
        for (auto it = s.begin(); it != lit; ++it) {
          int d = *it;
          if (isPalindrome(st, 0, l - d - 1) && m.count(st.substr(l - d))) {
            res.push_back({i, m[st.substr(l - d)]});
          }
          if (isPalindrome(st, d, l - 1) && m.count(st.substr(0, d))) {
            res.push_back({m[st.substr(0, d)], i});
          }
        }
      }
      return res;
    }
    bool isPalindrome(const string& s, int l, int r) {
      while (l < r) {
        if (s[l] != s[r]) {
          return false;
        }
        l++;
        r--;
      }
      return true;
    }
};