#include "../header.h"
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        int l = startIndex(nums, target, 0, nums.size() - 1);
        int r = endIndex(nums, target, 0, nums.size() - 1);
        return {l, r};
    }

    int startIndex(vector<int>& nums, const int target, int left, int right) {
        int mid = left + (right - left) / 2;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid -1;
            } else {
                left = mid + 1;
            }
        }
        return left < nums.size() && nums[left] == target ? left : -1;
    }

    int endIndex(vector<int>& nums, const int target, int left, int right) {
        int mid = left + (right - left) / 2;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right >= 0 && nums[right] == target ? right : -1;
    }
};

int main() {
    string s;
    cin >> s;
    int target;
    cin >> target;
    vector<int> nums = stringToIntegerVector(s);
    auto res = Solution().searchRange(nums, target);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}