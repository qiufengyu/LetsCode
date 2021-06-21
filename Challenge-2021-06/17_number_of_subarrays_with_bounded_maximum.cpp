#include "../header.h"

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0;
        int l = -1, r = -1;
        for (int i = 0; i < nums.size(); ++i) {
          if (nums[i] >= left) {
            r = i;
          }
          if (nums[i] > right) {
            l = i;
          }
          res += (r - l);
        }
        return res;        
    }
};