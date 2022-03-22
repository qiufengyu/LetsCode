#include "../header.h"

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        int size = nums.size();
        vector<bool> visited(size, false);
        return helper(nums, k, sum / k, visited, 0, 0);
    }

    bool helper(vector<int>& nums, int k, const int target, vector<bool>& visited, int start, int current) {
        if (k == 1) {
            return true;
        }
        if (current > target) {
            return false;
        }
        if (current == target) {
            return helper(nums, k - 1, target, visited, 0, 0);
        }
        for (int i = start; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            if (helper(nums, k, target, visited, i + 1, current + nums[i])) {
                return true;
            }
            visited[i] = false;
        }
        return false;
    }
};