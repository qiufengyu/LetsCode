#include "../header.h"

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0LL;
        priority_queue<int> pq(nums.begin(), nums.end());
        while (k) {
            int n = pq.top();
            res += n;
            pq.pop();
            pq.push((n + 2) / 3);
            k--;
        }
        return res;
    }
};