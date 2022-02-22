#include "../header.h"

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int minN = INT_MAX, res = INT_MAX;
        priority_queue<int> pq;
        for (int n: nums) {
            if (n % 2 == 1) {
                n = n * 2;
            }
            pq.push(n);
            minN = min(minN, n);
        }
        while (pq.top() % 2 == 0) {
            int t = pq.top();
            res = min(res, t - minN);
            t = t / 2;
            minN = min(minN, t);
            pq.push(t);
            pq.pop();
        }
        return min(res, pq.top() - minN);
    }
};