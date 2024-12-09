#include "../header.h"

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefix(nums.size(), 0);
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1];
            if ((nums[i-1] + nums[i]) % 2 == 0) {
                prefix[i]++;
            }
        }
        vector<bool> res;
        for (auto const& q: queries) {
            int l = q[0], r = q[1];
            int special = prefix[r] - (l > 0 ? prefix[l] : 0);
            res.push_back(special == 0);
        }
        return res;
    }
};