#include "../header.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sz = nums.size();
        unordered_map<int, int> preSum;
        preSum[0] = 1;
        int res = 0, sum = 0;
        for (int i = 0; i < sz; ++i) {
            sum += nums[i];
            if (preSum.count(sum - k)) {
                res += preSum[sum - k];
            }
            ++preSum[sum];
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> nums = stringToIntegerVector(s);
    cout << Solution().subarraySum(nums, k) << endl;
    return 0;
}