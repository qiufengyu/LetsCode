#include "../header.h"

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> preSum(n, 0);
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i-1] + nums[i];
        }
        auto li = lower_bound(preSum.begin(), preSum.end(), goal);
        int current = li - preSum.begin();
        int start = 0, ltarget = 0, rtarget = goal;
        int res = 0;
        while (current < n) {
            int lc = 0, rc = 0;
            while (start < current && preSum[start] == ltarget) {
                lc++;
                start++;
            }
            while (current < n && rtarget == preSum[current]) {
                rc++;
                current++;
            }
            if (goal == 0) {
                if (ltarget == 0) {
                    res += (rc * (rc + 1) / 2);
                } else {
                    res += (rc * (rc - 1) / 2);
                }                
            } else {
                if (ltarget == 0) {
                    res += (lc + 1) * rc;
                } else {
                    res += max(lc, 1) * rc;
                }                
            }            
            ltarget++;
            rtarget++;
        }
        return res;
    }
};

int main() {
    vector<int> nums{0, 1,1,1,1};
    int goal = 3;
    cout << Solution().numSubarraysWithSum(nums, goal) << endl;
    return 0;
}