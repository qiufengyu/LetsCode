#include "../header.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; ++i) {
          vector<int> t(i, 1);
          for (int j = 1; j < i - 1; ++j) {
            t[j] = res[i-2][j-1] + res[i-2][j];
          }
          res.push_back(t);
        }
        return res;
    }
};

int main() {
  int n = 1;
  vector<vector<int>> ans = Solution().generate(n);
  print_vector(ans);
  return 0;
}