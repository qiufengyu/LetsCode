#include "../header.h"

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto const& itv: intervals) {
            int l = itv[0], r = itv[1];
            if (pq.empty()) {
                pq.push(r);
            } else {
                int tp = pq.top();            
                if (tp < l) {
                    pq.pop();
                    pq.push(r);
                } else {
                    pq.push(r);
                }
            }
        }
        return (int)pq.size();
    }
};