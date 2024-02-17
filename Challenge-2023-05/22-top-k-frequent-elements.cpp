#include "../header.h"

class Solution {
public:    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (auto const& n: nums) {
            ++cnt[n];
        }
        auto cmp = [&cnt](const int& i, const int& j) -> bool {
            return cnt[i] > cnt[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (auto const& p: cnt) {
            pq.push(p.first);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while (k > 0) {
            res.push_back(pq.top());
            pq.pop();
            --k;
        }
        return res;
    }
};