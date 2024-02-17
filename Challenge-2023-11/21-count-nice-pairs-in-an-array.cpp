#include "../header.h"

class Solution {
public:
    int rev(int n) {
        int r = 0;
        while (n > 0) {
            r *= 10;
            r += (n % 10);
            n /= 10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int d = nums[i] - rev(nums[i]);
            ++m[d];
        }
        long res = 0L;
        for (auto const& p: m) {
            res += (long)p.second * (p.second-1) / 2;
            res %= 1000000007;
        }
        return (int)res;
    }
};

int main() {
    vector<int> nums {13,10,35,24,76};
    cout << Solution().countNicePairs(nums) << endl;
    return 0;
}