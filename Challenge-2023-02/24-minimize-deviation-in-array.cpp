#include "../header.h"

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mn = INT_MAX;
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 1) {
                nums[i] *= 2;
            }
            pq.push(nums[i]);
            mn = min(mn, nums[i]);
        }
        int res = INT_MAX;
        while (!pq.empty() && (pq.top() % 2 == 0)) {
            int tp = pq.top();
            pq.pop();
            res = min(res, tp - mn);
            tp /= 2;
            mn = min(mn, tp);
            pq.push(tp);
        }
        return min(res, pq.top() - mn);
    }
};