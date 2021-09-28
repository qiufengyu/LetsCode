#include "../header.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (auto const n: nums1) {
            ++m[n];
        }
        vector<int> res;
        for (auto const n: nums2) {
            if (m.count(n) > 0 && m[n] > 0) {
                --m[n];
                res.push_back(n);
            }
        }
        return res;
    }
};