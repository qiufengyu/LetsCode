#include "header.h"

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto compare = [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            return a.first * a.first + a.second * a.second > b.first * b.first + b.second * b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> q(compare);
        vector<vector<int>> res;
        for (auto &p: points) {
            q.push({p[0], p[1]});
        }
        int kk = 0;
        while (kk < K) {
            pair<int, int> p = q.top();
            q.pop();
            res.push_back({p.first, p.second});
            kk++;
        }
        return res;        
    }
};

int main() {
    vector<vector<int>> points {{3,3}, {5,-1},{-2,-4}};
    int K = 2;
    auto res = Solution().kClosest(points, K);
    print2DVector(res);
    return 0;
}