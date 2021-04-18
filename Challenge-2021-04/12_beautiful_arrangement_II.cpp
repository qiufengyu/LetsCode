#include "../header.h"

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int i = 1, j = n;
        while (k > 1) {          
          if (k % 2 == 0) {
            res.push_back(j--);
          } else {
            res.push_back(i++);
          }
          k--;
        }
        while (i <= j) {
          res.push_back(i++);
        }
        return res;
    }
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> res = Solution().constructArray(n, k);
  print_vector(res);
  return 0;
}