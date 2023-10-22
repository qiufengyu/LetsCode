#include "../header.h"

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, set<int>> graph;
        vector<int> inDeg(n + 1, 0);
        for (auto const& r: relations) {
            graph[r[0]].insert(r[1]);
            ++inDeg[r[1]];
        }
        queue<int> q;
        vector<int> maxTime(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
                maxTime[i] = time[i - 1];
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int nbr: graph[node]) {
                maxTime[nbr] = max(maxTime[nbr], maxTime[node] + time[nbr-1]);
                --inDeg[nbr];
                if (inDeg[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, maxTime[i]);
        }
        return res;
    }
};