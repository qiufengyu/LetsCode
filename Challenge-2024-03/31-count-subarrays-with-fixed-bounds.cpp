#include "../header.h"

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int start = 0, n = nums.size();
        long long res = 0LL;
        queue<int> q;
        q.push(-1);
        while (start < n) {
            if (nums[start] < minK || nums[start] > maxK) {
                q.push(start);
            }
            start++;
        }
        q.push(n);
        start = q.front() + 1;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            int end = f, mx = INT_MIN, mn = INT_MAX;
            int i = start, mxi = start, mni = start;
            while (i < end) {
                if (nums[i] >= mx) {
                    mx = nums[i];
                    mxi = i;
                }
                if (nums[i] <= mn) {
                    mn = nums[i];
                    mni = i;
                }
                if (mx == maxK && mn == minK) {
                    res += (min(mxi, mni) - start + 1);
                }
                i++;
            }
            start = f + 1;
        }
        return res;
    }
};