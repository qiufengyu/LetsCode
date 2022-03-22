#include "../header.h"
#include <functional>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = accumulate(nums.begin(), nums.end(), 1, std::multiplies<int>());
        vector<int> res(nums.size(), 0);
        if (p == 0) {
            int zcount = 0, zp = 1, zindex = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == 0) {
                    zcount++;
                    zindex = i;
                } else {
                    zp *= nums[i];
                }
            }
            if (zcount > 1) {
                return res;
            } else {
                res[zindex] = zp;
                return res;
            }
        } else {      
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i])
                res[i] = p / nums[i];
            }
        }
        return res;
    }
};