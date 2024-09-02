#include "../header.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> us;
        us.insert(1);
        pq.push(1);
        while (!pq.empty() && n > 0) {
            n--;
            int tp = pq.top();
            pq.pop();
            if (n == 0) {
                return (int)tp;
            }
            if (us.count(tp * 2LL) == 0) {
                pq.push(tp * 2LL);
                us.insert(tp * 2LL);
            }
            if (us.count(tp * 3LL) == 0) {
                pq.push(tp * 3LL);
                us.insert(tp * 3LL);
            } 
            if (us.count(tp * 5LL) == 0) {
                pq.push(tp * 5LL);
                us.insert(tp * 5LL);
            }            
        }
        return -1;
    }
};