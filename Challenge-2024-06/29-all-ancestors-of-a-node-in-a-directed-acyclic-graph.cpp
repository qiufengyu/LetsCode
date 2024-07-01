#include "../header.h"

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        unordered_map<int, unordered_set<int>> graph;
        for (auto const& edge: edges) {
            inDegree[edge[1]]++;
            graph[edge[0]].insert(edge[1]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<set<int>> resSet(n);
        while (!q.empty()) {
            int sz = q.size();
            while (sz) {
                int tp = q.front();
                q.pop();
                auto nbrs = graph[tp];
                for (auto const& nbr: nbrs) {
                    if (inDegree[nbr] > 0) {
                        inDegree[nbr]--;
                        if (inDegree[nbr] == 0) {
                            q.push(nbr);
                        }
                        resSet[nbr].insert(tp);
                        resSet[nbr].insert(resSet[tp].begin(), resSet[tp].end());
                    }
                }
                sz--;
            }
        }
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) {
            for (auto x: resSet[i]) {
                res[i].push_back(x);
            }
        }
        return res;
    }
};