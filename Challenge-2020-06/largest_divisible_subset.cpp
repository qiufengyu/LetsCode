#include "header.h"

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1) {
            return nums;
        }
        sort(nums.begin(), nums.end());
        vector<int> dp (sz, 1);
        vector<int> parent(sz, -1);
        vector<int> res;
        int max_index = 0;
        for (int i = 1; i < sz; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if (dp[max_index] < dp[i]) {
                max_index = i;
            }
        }
        while (max_index >= 0) {
            res.insert(res.begin(), nums[max_index]);
            max_index = parent[max_index];
        }
        return res;
    }
};

int main() {
    vector<int> v {1, 16, 7, 8, 4};
    vector<int> r = Solution().largestDivisibleSubset(v);
    for (auto &x: r) {
        cout << x << " ";
    }
    cout<< endl;
    return 0;
}