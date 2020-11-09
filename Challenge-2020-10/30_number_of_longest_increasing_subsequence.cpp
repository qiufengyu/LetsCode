#include "../header.h"

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 2) {
            return sz;
        }
        vector<int> c(sz, 1);
        vector<int> l(sz, 1);
        for (int i = 1; i < sz; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (l[j] + 1 > l[i]) {
                        l[i] = l[j] + 1;
                        c[i] = c[j];
                    } else if (l[j] + 1 == l[i]) {
                        c[i] += c[j];
                    }
                }
            }
        }
        int maxLen = *max_element(l.begin(), l.end());
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            if (l[i] == maxLen) {
                ans += c[i];
            }
        }
        return ans;
    }
};