#include "../header.h"

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        int res = 0;
        for (auto const& p: m) {
            if (p.second == 1) {
                return -1;
            }
            res += ((p.second + 2) / 3);
        }
        return res;
    }
};