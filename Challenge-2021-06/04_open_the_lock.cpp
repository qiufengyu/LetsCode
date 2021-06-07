#include "../header.h"

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
      unordered_set<string> deadset;
      for (auto const& d: deadends) {
        deadset.insert(d);
      }
      if (deadset.count("0000")) {
        return -1;
      }
      queue<string> q;
      q.push("0000");
      int depth = 0;
      while (!q.empty()) {
        int size = q.size();        
        for (int i = 0; i < size; ++i) {
          string s = q.front(); 
          q.pop();
          if (s == target) {
            return depth;
          }
          for (int j = 0; j < 4; ++j) {
            for (int l = -1; l < 2; l += 2) {
              char x = (s[j] - '0' + 10 + l) % 10 + '0';
              string ss = s;
              ss[j] = x;
              if (!deadset.count(ss)) {
                q.push(ss);
                deadset.insert(ss);
              }
            }
          }
        }
        depth++;
      }
      return -1;
    }
};