#include "../header.h"

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int start = 0, end = n;
        while (start <= end) {
            int m = start + (end - start) / 2;
            auto lb = lower_bound(nums.begin(), nums.end(), m);
            int idx = nums.end() - lb;
            if (idx == m) {
                return m;
            } else if (idx < m) {
                end = m - 1;
            } else {
                start = m + 1;
            }
        }
        return -1;
    }
};