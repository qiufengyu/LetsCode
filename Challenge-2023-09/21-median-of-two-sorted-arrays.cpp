#include "../header.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int m = nums1.size(), n = nums2.size();
        int l = 0, r = m;
        bool two = ((m + n) % 2 == 0);
        while (l <= r) {
            int pa = (l + r) / 2;
            int pb = (m + n + 1) / 2 - pa;
            int maxLeftA = (pa == 0) ? INT_MIN : nums1[pa-1];
            int minRightA = (pa == m) ? INT_MAX : nums1[pa];
            int maxLeftB = (pb == 0) ? INT_MIN : nums2[pb-1];
            int minRightB = (pb == n) ? INT_MAX : nums2[pb];
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if (two) {
                    return 0.5 * (max(maxLeftA, maxLeftB) + min(minRightA, minRightB));
                } else {
                    return max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                r = pa - 1;
            } else {
                l = pa + 1;
            }
        }
        return -1.0;
    }
};