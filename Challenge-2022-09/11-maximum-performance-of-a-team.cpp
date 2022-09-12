#include "../header.h"

typedef pair<int, int> PII;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<PII> es(n);
        for (int i = 0; i < n; ++i) {
            es[i] = {efficiency[i], speed[i]};
        }
        sort(rbegin(es), rend(es));
        long s = 0,  res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (PII const& e: es) {
            pq.emplace(e.second);
            s += e.second;
            if (pq.size() > k) {
                s -= pq.top();
                pq.pop();
            }
            res = max(res, s * e.first);
        }
        return (int)(res % 1000000007);
    }
};