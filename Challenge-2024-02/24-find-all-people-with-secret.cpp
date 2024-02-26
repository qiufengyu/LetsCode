#include "../header.h"

typedef pair<int, int> PII;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<PII>> graph(n);
        for (auto const& m: meetings) {
            graph[m[0]].push_back({m[1], m[2]});
            graph[m[1]].push_back({m[0], m[2]});
        }
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});
        vector<bool> visited(n, false);
        while (!pq.empty()) {
            PII tp = pq.top();
            pq.pop();
            int time = tp.first, person = tp.second;
            if (!visited[person]) {
                visited[person] = true;
                for (auto const& p: graph[person]) {
                    if (!visited[p.first] && p.second >= time) {
                        pq.push({p.second, p.first});
                    }
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};