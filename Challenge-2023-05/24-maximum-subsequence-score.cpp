#include "../header.h"

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums1.size(); ++i) {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.begin(), v.end(), [](pair<int, int> const& p1, pair<int, int> const& p2) -> bool {
            return p1.first > p2.first;
        });
        long long res = 0;
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k - 1; ++i) {
            sum += v[i].second;
            pq.push(v[i].second);
        }
        for (int i = k - 1; i < nums1.size(); ++i) {
            sum += v[i].second;
            pq.push(v[i].second);
            res = max(res, sum * v[i].first);
            sum -= pq.top();
            pq.pop();
        }
        return res;
    }
};