#include "../header.h"

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> m;
        int res = 0;
        for (auto x: nums) {
            ++m[x];
        }
        if (k == 0) {
            for (auto e: m) {
                if (e.second > 1) {
                    res++;
                }
            }
        } else {
            for (auto e: m) {
                if (m.count(k + e.first) > 0) {
                    res++;
                }
            }
        }
        return res;
    }
};