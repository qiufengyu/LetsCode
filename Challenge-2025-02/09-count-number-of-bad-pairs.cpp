#include "../header.h"

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i] - i]++;
        }
        long long res = (long long)(nums.size() - 1) * nums.size() / 2LL;
        for (auto const& p: mp) {
            if (p.second > 1) {
                res -= (p.second * (p.second - 1)) / 2;
            }
        }
        return res;
    }
};