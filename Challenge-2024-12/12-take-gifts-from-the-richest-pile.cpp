#include "../header.h"

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = accumulate(gifts.begin(), gifts.end(), 0LL);
        priority_queue<int> pq(gifts.begin(), gifts.end());
        int rest = 0;
        while (k) {
            int tp = pq.top();
            pq.pop();
            int s = sqrt(tp);
            rest = s;
            sum -= (tp - s);
            pq.push(rest);
            k--;
        }
        return sum;
    }
};