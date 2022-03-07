#include "../header.h"

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> m;
        for (auto num: nums) {
            ++m[num];
        }
        int r1 = 0, r2 = 0, temp = 0, key = -1;
        for (auto kv: m) {
            temp = r1;
            if (kv.first == key + 1) {
                r1 = max(r1, r2 + kv.first * kv.second);
            } else {
                r1 = r1 + kv.first * kv.second;
            }
            r2 = temp;            
            key = kv.first;
        }
        return max(r1, r2);
    }
};