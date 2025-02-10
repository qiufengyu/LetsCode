#include "../header.h"

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        int res = 0;
        for (auto const& p: mp) {
            int l = p.second;
            res += (l * (l - 1) / 2);
        }
        return res * 8;
    }
};