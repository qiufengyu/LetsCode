#include "../header.h"

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> comb(n+1, vector<long long>(n+1, 0LL));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= min(i, n); ++j) {
                comb[i][j] = ((comb[i-1][j-1] + comb[i-1][j]) % 1000000007LL);
            }
        }
        return dfs(nums, comb) - 1;
    }

    long long dfs(vector<int> const& nums, vector<vector<long long>>& comb) {
        if (nums.size() <= 2) {
            return 1;
        }
        vector<int> left, right;
        int pivot = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < pivot) {
                left.push_back(nums[i]);
            }
            if (nums[i] > pivot) {
                right.push_back(nums[i]);
            }
        }
        // need to module again and again to avoid overflow
        return (((comb[left.size()+right.size()][left.size()] % 1000000007LL) * dfs(left, comb) % 1000000007LL) * dfs(right, comb) % 1000000007LL);
    }
};