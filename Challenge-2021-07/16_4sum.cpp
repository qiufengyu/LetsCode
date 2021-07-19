#include "../header.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int sz = nums.size();
        if (sz < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < sz - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
                break;
            }
            if (nums[i] + nums[sz-3] + nums[sz-2] + nums[sz-1] < target) {
                continue;
            }
            int rest3 = target - nums[i];
            for (int j = i + 1; j < sz - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                if (nums[j] + nums[j+1] + nums[j+2] > rest3) {
                    break;
                }
                if (nums[j] + nums[sz-2] + nums[sz-1] < rest3) {
                    continue;
                }
                int left = j + 1, right = sz - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right-1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;      
    }
};