#include "../header.h"

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum = accumulate(piles.begin(), piles.end(), 0);
        for (int i = 0; i < piles.size(); ++i) {
            pq.push(piles[i]);
        }
        while (k > 0) {
            int t = pq.top();
            pq.pop();
            pq.push(t - t / 2);
            sum -= (t / 2);
            --k;
        }
        return sum;
    }
};