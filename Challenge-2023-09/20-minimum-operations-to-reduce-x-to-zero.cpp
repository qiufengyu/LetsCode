#include "../header.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;        
        int n = nums.size();
        if (target == 0) {
            return n;
        }
        int left = 0, current = 0, res = INT_MAX;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            current += num;
            while (left < i && current > target) {
                current -= nums[left];
                left++;
            }
            if (current == target) {
                res = min(res, n - (i - left + 1));
            }
        }
        if (res == INT_MAX) {
            return -1;
        }
        return res;
    }
};

int main() {
    vector<int> nums{1,1,4,2,3};
    int x = 5;
    cout << Solution().minOperations(nums, x) << endl;
    return 0;
}