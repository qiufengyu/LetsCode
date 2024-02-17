#include "../header.h"

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            int r = s1 - s2;
            if (r > 0) {
                pq.push(r);
            }
        }
        if (pq.size() == 1) {
            return pq.top();
        }
        return 0;
    }
};