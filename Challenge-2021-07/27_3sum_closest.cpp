#include "../header.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < sz; ++i) {
            // skip duplicate numbers
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i + 1, k = sz - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return target;
                }     
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }
                if (sum > target) {
                    // k back
                    int tk = k - 1;
                    while (j < tk && nums[tk] == nums[k]) {
                        tk--;
                    }
                    k = tk;
                } else {
                    // j forward
                    int tj = j + 1;
                    while (tj < k && nums[tj] == nums[j]) {
                        tj++;
                    }
                    j = tj;
                }
            }
        }
        return closest;
    }
};