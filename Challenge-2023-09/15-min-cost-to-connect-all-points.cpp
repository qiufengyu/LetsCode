#include "../header.h"

typedef pair<int, int> PII;

struct cmp {
    bool operator()(const PII& p1, const PII& p2) {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        priority_queue<PII, vector<PII>, cmp> pq;
        unordered_map<int, int> cache;
        vector<bool> visited(n, false);
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto e = pq.top();
            pq.pop();
            int cost = e.first, vertex = e.second;
            if (!visited[vertex]) {
                visited[vertex] = true;
                res += cost;
                for (int i = 0; i < n; ++i) {
                    if (!visited[i]) {
                        int d = getDist(points[vertex], points[i]);
                        if (cache.count(i) == 0) {
                            cache[i] = d;
                            pq.emplace(d, i);
                        } else if (cache[i] > d) {
                            cache[i] = d;
                            pq.emplace(d, i);
                        }
                    }
                }
            }
        }
        return res;
    }

    int getDist(vector<int>& p1, vector<int>& p2) const {
        return abs(p1[0]-p2[0]) + abs(p1[1] - p2[1]);
    }
};