#include "../header.h"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> preSum;
        preSum[0] = -1;
        int sum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                sum--;
            } else {
                sum++;
            }
            if (preSum.count(sum)) {
                res = max(res, i - preSum[sum]);
            } else {
                preSum[sum] = i;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums;
    cout << Solution().findMaxLength(nums) << endl;
    return 0;
}