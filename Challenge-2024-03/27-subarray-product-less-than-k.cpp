#include "../header.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, end = 0, n = nums.size(), res = 0;
        long long p = 1;
        while (end < n) {
            p *= nums[end];
            while (p >= k && start <= end) {
                p /= nums[start];
                start++;
            }
            if (p < k) {
                res += (end - start + 1);
            }
            end++;
        }
        return res;
    }
};

int main() {
    vector<int> nums{10,5,2,6};
    int k = 100;
    cout << Solution().numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}