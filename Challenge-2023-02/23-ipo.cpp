#include "../header.h"

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> pc;
        for (int i = 0; i < profits.size(); ++i) {
            pc.push_back({capital[i], profits[i]});
        }
        sort(pc.begin(), pc.end());
        priority_queue<int> pq;
        int idx = 0;
        while (k > 0) {
            k--;
            while (idx < profits.size() && pc[idx].first <= w) {
                pq.push(pc[idx].second);
                ++idx;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else {
                // no capitals and profits can be achieved
                break;
            }

        }
        return w;
    }
};