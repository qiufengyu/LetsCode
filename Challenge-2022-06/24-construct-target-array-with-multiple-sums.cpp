#include "../header.h"

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(target.begin(), target.end());
        long sum = accumulate(target.begin(), target.end(), 0L);
        while (true) {
            int t = pq.top();
            sum -= t;
            if (t == 1 || sum == 1) {
                return true;
            }
            if (t < sum || sum == 0 || t % sum == 0) {
                return false;
            }
            t = t % sum;
            sum += t;
            pq.push(t);
        }
        return true;
    }
};