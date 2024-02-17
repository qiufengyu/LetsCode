#include "../header.h"

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto const& n: nums) {
            ++m[n];
        }
        int n = nums.size() / 3;
        vector<int> res;
        for (auto const& p: m) {
            if (p.second > n) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};