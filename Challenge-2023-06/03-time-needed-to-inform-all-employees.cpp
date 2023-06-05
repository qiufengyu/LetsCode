#include "../header.h"

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<int> q;
        vector<int> times(n, -1);
        int res = INT_MAX;
        q.push(headID);
        times[headID] = 0;
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                graph[manager[i]].push_back(i);
            }
        }
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                int f = q.front();
                q.pop();
                times[f] += informTime[f];
                for (auto const i: graph[f]) {
                    if (times[i] == -1) {
                        q.push(i);
                        times[i] = times[f];
                    }
                }
                --sz;
            }
        }
        return *max_element(times.begin(), times.end());
    }
};