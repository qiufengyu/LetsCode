#include "../header.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lIndex = lower_bound(nums, target);
        int rIndex = upper_bound(nums, target) - 1;
        if (lIndex <= rIndex && rIndex < nums.size() && nums[lIndex] == target && nums[rIndex] == target) {
          return {lIndex, rIndex};
        }
        return {-1, -1};
    }

    int lower_bound(vector<int>& nums, int target) {
      int l = 0, r = nums.size();
      int m = l + (r - l) / 2;
      while (l < r) {
        m = l + (r - l) / 2;
        if (target <= nums[m]) {
          r = m;
        } else {
          l = m + 1;
        }
      }
      return l;
    }

    int upper_bound(vector<int>& nums, int target) {
      int l = 0, r = nums.size();
      int m = l + (r - l) / 2;
      while (l < r) {
        m = l + (r - l) / 2;
        if (target >= nums[m]) {
          l = m + 1;
        } else {
          r = m;
        }
      }
      return l;
    }

};