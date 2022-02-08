#include "../header.h"

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> m12, m34;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++m12[nums1[i] + nums2[j]];
                ++m34[nums3[i] + nums4[j]];
            }
        }
        int res = 0;
        for (pair<int, int> const& p: m12) {
            res += p.second * (m34[-p.first]);
        }
        return res;
    }
};