#include "../header.h"

class Solution {
    int digitSum(int n) {
        int s = 0;
        while (n) {
            s += (n % 10);
            n /= 10;
        }
        return s;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = -1;
        for (int i = 0; i < nums.size(); i++) {
            int ds = digitSum(nums[i]);
            if (mp.count(ds) != 0) {
                mp[ds] = max(nums[i], mp[ds]);
                res = max(nums[i] + ds, res);
            } else {
                mp[ds] = nums[i];
            }
        }
        return res;
    }
};