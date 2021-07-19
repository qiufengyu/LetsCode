#include "../header.h"

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 3) {
            return 0;
        }
        int res = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < sz - 2; ++i) {
            int j = i + 1, k = sz - 1;
            while (j < k) {
                if (nums[j] + nums[k] > nums[i]) {
                    res += (k - j);
                    j++;
                } else {
                    k--;
                }
            }
        }
        return res;        
    }
};