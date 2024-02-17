#include "../header.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0], count = 1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] != res) {
                count--;
                if (count == 0) {
                    res = nums[i];
                    count = 1;
                }
            }
            else {
                count++;
            }
        }
        return res;
    }
};