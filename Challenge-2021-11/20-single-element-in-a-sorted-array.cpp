#include "../header.h"

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int sz = nums.size();
        int s = 0, e = sz;
        if (sz == 1) {
            return nums[0];
        }
        int mid = s + (e - s) / 2;
        while (s < e) {
            mid = s + (e - s) / 2;
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    s = mid + 1;
                } else {
                    e = mid;
                }
            } else {
                if (nums[mid] == nums[mid - 1]) {
                    s = mid + 1;
                } else {
                    e = mid;
                }
            }
        }
        return nums[s];
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    cout << Solution().singleNonDuplicate(nums) << endl;
    return 0;
}