#include "../header.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, current = 0, res = 0;
        while (current < nums.size() - 1) {
          ++res;
          int prev = current;
          while (i <= prev) {
            current = max(current, i + nums[i]);
            ++i;
          }
          if (current == prev) {
            return -1;
          }
        }
        return res;
    }
};