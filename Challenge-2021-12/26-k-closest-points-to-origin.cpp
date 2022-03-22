#include "../header.h"

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](vector<int>& left, vector<int>& right) { 
            return (left[0]*left[0] + left[1]*left[1]) < (right[0]*right[0] + right[1]*right[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        int n = points.size();
        for (int i = 0; i < k; ++i) {
            pq.push(points[i]);
        }
        for (int j = k; j < n; ++j) {
            pq.push(points[j]);
            pq.pop();
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;                
    }
};