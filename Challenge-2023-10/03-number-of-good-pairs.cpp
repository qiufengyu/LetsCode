#include "../header.h"

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            ++m[nums[i]];
        }
        int res = 0;
        for (auto const& p: m) {
            res += (p.second * (p.second - 1) / 2);
        }
        return res;
    }
};