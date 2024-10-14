#include "../header.h"

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int r = 0;
        int res = n;
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int remainder = sum % p;
        if (remainder == 0) {
            return 0;
        }
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            r += nums[i];
            r %= p;
            int target = (r - remainder + p) % p;
            if (mp.count(target)) {
                res = min(res, i - mp[target]);
            }
            mp[r] = i;
        }
        if (res == n) {
            return -1;
        }
        return res;
    }
};

int main() {
    vector<int> nums{8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2};
    int p = 148;
    cout << Solution().minSubarray(nums, p) << endl;
    return 0;
}