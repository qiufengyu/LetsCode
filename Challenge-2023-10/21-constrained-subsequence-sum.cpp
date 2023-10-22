#include "../header.h"

typedef pair<int, int> PII;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<PII> pq;
        pq.emplace(nums[0], 0);
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            while (i - pq.top().second > k) {
                pq.pop();
            }
            int current = max(0, pq.top().first) + nums[i];
            res = max(res, current);
            pq.emplace(current, i);
        }
        return res;
    }
};