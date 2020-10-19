#include "../header.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        } else {
            return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
        }
    }

    int rob(vector<int>& nums, int start, int end) {
        int r1 = 0, r2 = 0;
        for (int i = start; i < end; i++) {
            if (i % 2 == 0) {
                r2 = max(r2 + nums[i], r1);
            } else {
                r1 = max(r1 + nums[i], r2);
            }
        }
        return max(r1, r2);
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    cout << Solution().rob(nums) << endl;
    return 0;
}