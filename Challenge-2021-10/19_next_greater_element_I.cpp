#include "../header.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        unordered_map<int, int> m;
        for (int i = 0; i < nums2.size(); ++i) {
            m[nums2[i]] = i;
        }
        for (int i = 0; i < nums1.size(); ++i) {
            res[i] = -1;
            int start = m[nums1[i]];
            for (int j = start + 1; j < nums2.size(); ++j) {
                if (nums2[j] > nums1[i]) {
                    res[i] = nums2[j];
                    break;
                }
            }
        }
        return res;
    }
};