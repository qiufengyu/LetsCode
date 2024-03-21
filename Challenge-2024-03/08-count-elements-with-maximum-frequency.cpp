#include "../header.h"

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxF = 0;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            maxF = max(maxF, m[nums[i]]);
        }
        int res = 0;
        for (auto const& p: m) {
            if (p.second == maxF) {
                res += maxF;
            }
        }
        return res;
    }
};