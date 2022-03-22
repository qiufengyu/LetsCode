#include "../header.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int k1 = k % nums.size();
        reverse(nums.end()-k1, nums.end());
        reverse(nums.begin(), nums.end()-k1);
        reverse(nums.begin(), nums.end());
    }
};