#include "../header.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
      int res = 0;
      int len = 2;
      if (A.size() < 3) {
        return res;
      }
      for (size_t i = 0; i < A.size() - 2; i++) {
        if (A[i] + A[i+2] == 2 * A[i+1]) {
          len++;
        } else {          
          res += (len - 1) * (len - 2) / 2;
          len = 2;
        }
      }
      res += (len - 1) * (len - 2) / 2;
      return res;
    }
};