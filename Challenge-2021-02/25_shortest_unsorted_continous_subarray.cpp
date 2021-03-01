#include "../header.h"

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int sz = nums.size();
        int i = 0, j = sz - 1;
        int iIndex = 0, jIndex = j;
        int iVal = nums[i], jVal = nums[j];
        // i -> end of the subarray
        // right most element that has bigger values on left side
        while (i < sz) {            
            if (iVal > nums[i]) {
                iIndex = i;
            } else {
                iVal = nums[i];
            }
            ++i;
        }
        if (iIndex == 0) {
            return 0;
        }
        // j -> start of the subarray
        // left most element that has smaller values on the right side
        while (j >= 0) {
            if (jVal < nums[j]) {
                jIndex = j;
            } else {
                jVal = nums[j];
            }
            --j;
        }
        return iIndex - jIndex + 1;
    }
};
