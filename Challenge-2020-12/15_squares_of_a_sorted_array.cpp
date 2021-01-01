#include "../header.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        nums[i] *= nums[i];
      }
      int index = 0;
      int val = nums[0];
      for (int i = 1; i < n; i++) {
        if (nums[i] < val) {
          val = nums[i];
            index = i;
        }
      }
      int l = index - 1, r = index + 1;
      vector<int> res {nums[index]};
      while (l >= 0 && r < n) {
        if (nums[l] <= nums[r]) {
          res.push_back(nums[l--]);
        } else if (nums[l] > nums[r]) {
          res.push_back(nums[r++]);
        }
      }
      while (l >= 0) {
        res.push_back(nums[l--]);
      }
      while (r < n) {
        res.push_back(nums[r++]);
      }
      return res;
    }
};

int main() {
  string s;
  cin >> s;
  vector<int> v = stringToIntegerVector(s);
  vector<int> r = Solution().sortedSquares(v);
  print_vector<int>(r);
  return 0;
}