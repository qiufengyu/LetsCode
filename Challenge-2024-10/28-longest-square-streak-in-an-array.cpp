#include "../header.h"

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<long long, bool> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp.emplace((long long)nums[i], false);
        }
        int res = 0;
        for (auto const& i: mp) {
            long long start = i.first;
            bool used = i.second;
            if (!used) {
                int length = 1;
                while (mp.count(start * start)) {
                    mp[start*start] = true;                    
                    start = start * start;
                    length++;
                    res = max(res, length);
                }
            }            
        }
        return res <= 1 ? -1 : res;
    }
};