#include "../header.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<int> res;
        for (auto const& n: s1) {
            if (s2.count(n)) {
                res.push_back(n);
            }
        }
        return res;
    }
};