#include "../header.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> res;
      string current = "";
      helper(res, current, n * 2, 0, 0);
      return res;
        
    }

    void helper(vector<string>& res, string current, int total, int l, int r) {
      if (total <= 0) {
        if (l == r) {
          res.push_back(current);
        }
        return;
      }
      helper(res, current + "(", total - 1, l + 1, r);
      if (l > r) {
        helper(res, current + ")", total - 1, l, r + 1);
      }
    }
};