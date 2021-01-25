#include "../header.h"

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1;
        for (int i = 0; i < nums.size(); i++) {
          if (nums[i]) {
            if (prev != -1) {
              if (i - prev <= k) {
                return false;
              }
            }
            prev = i;
          }
        }
        return true;
    }
};