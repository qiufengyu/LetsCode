#include "../header.h"

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>>m;
        for (int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                int f = q.front();
                q.pop();
                if (f == n - 1) {
                    return res;
                }
                if (f + 1 < n && !visited[f+1]) {
                    visited[f+1] = true;
                    q.push(f+1);
                }
                if (f - 1 >= 0 && !visited[f-1]) {
                    visited[f-1] = true;
                    q.push(f-1);
                }
                auto fequals = m.find(arr[f]);
                if (fequals != m.end()) {
                    for (auto e: fequals->second) {
                        if (!visited[e]) {
                            visited[e] = true;
                            q.push(e);
                        }
                    }
                    m.erase(fequals);
                }
                sz--;
            }
            res++;
        }
        return n-1;
    }
};
