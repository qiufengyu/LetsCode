#include "../header.h"

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -1, mx = INT_MIN, mn = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            mx = max(mx, nums[i]);
            if (mx > nums[i]) {
                end = i;
            }
        }
        for (int j = nums.size() - 1; j >= 0; --j) {
            mn = min(mn, nums[j]);
            if (mn < nums[j]) {
                start = j;
            }
        }
        if (start == end) {
            return 0;
        }
        return end - start + 1;        
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    cout << Solution().findUnsortedSubarray(nums) << endl;
    return 0;
}