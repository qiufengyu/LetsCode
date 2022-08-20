#include "../header.h"

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int m = (left + right) / 2;
        while (left <= right) {
            if (nums[m] == target) {
                return true;
            }
            if (nums[left] < nums[m]) {
                if (target >= nums[left] && target < nums[m]) {
                    right = m - 1;
                } else {
                    left = m + 1;
                }
            } else if (nums[left] == nums[m]) {
                ++left;
            } else {
                if (target > nums[m] && target <= nums[right]) {
                    left = m + 1;
                } else {
                    right = m - 1;
                }
            }
            m = (left + right) / 2;
        }
        return false;
    }
};

int main() {
    string s;
    cin >> s;
    int target;
    cin >> target;
    vector<int> nums = stringToIntegerVector(s);
    cout << Solution().search(nums, target) << endl;
    return 0;
}
