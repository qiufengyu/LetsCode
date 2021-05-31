#include "../header.h"

class Solution {
public:
    int maxProduct(vector<string>& words) {
      int n = words.size();
      unordered_map<string, int> m;
      for (auto& word: words) {
        int x = 0;
        for (auto& c: word) {
          x |= (1 << (c - 'a'));
        }
        m[word] = x;
      }
      int res = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
          if ((m[words[i]] & m[words[j]]) == 0) {
            res = max(res, (int)(words[i].size() * words[j].size()));
          }
        }
      } 
      return res;       
    }
};