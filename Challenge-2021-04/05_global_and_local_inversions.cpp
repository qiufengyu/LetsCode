#include "../header.h"

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int sz = A.size();
        int temp = A[0];
        for (int i = 0; i < sz - 2; ++i) {
          temp = max(temp, A[i]);
          if (A[i+2] < temp) {
            return false;
          }
        }
        return true;
    }
};