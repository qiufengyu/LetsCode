#include "../header.h"

class Solution {
    vector<int> temp;
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int total = 1 << n; // n <= 10
        for (int mask = 0; mask < total; ++mask) {
            temp.clear();
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    // the previous is not pick this time
                    // actually it's a duplicate this round
                    if (i > 0 && nums[i] == nums[i-1] && ((mask >> (i-1)) & 1) == 0) {
                        flag = false;
                        break;
                    }
                    temp.push_back(nums[i]);
                }
            }
            if (flag) {
                res.push_back(temp);
            }
        }
        return res;
    }
};