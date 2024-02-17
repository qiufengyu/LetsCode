#include "../header.h"

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        int res = 0;
        unordered_map<int, vector<int>> rm;
        for (int i = 0; i < n; i++) {
            for (auto const& r: routes[i]) {
                rm[r].push_back(i);
            }
        }
        vector<bool> visitedBus(n, false);
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int sz = q.size();
            while (sz) {
                int frt = q.front();
                q.pop();
                if (frt == target) {
                    return res;
                }
                for (int x: rm[frt]) {
                    if (!visitedBus[x]) {
                        visitedBus[x] = true;
                        for (int nxt: routes[x]) {
                            q.push(nxt);
                        }
                    }
                }
                sz--;
            }
            res++;
        }
        return -1;
    }
};