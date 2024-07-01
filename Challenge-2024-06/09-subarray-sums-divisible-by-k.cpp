#include "../header.h"

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum = ((sum + nums[i]) % k + k ) % k;
            mp[sum]++;
        }
        int res = 0;
        for (auto const& p: mp) {
            cout << p.first << ": " << p.second << endl;
            res += p.second * (p.second - 1) / 2;
        }
        return res;
    }
};

int main() {
    vector<int> nums{4,5,0,-2,-3,1};
    int k = 5;
    cout << Solution().subarraysDivByK(nums, k) << endl;
    return 0;
}