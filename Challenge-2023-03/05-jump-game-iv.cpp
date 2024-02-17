#include "../header.h"

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            return 0;
        }
        unordered_map<int, vector<int>> m;
        vector<bool> visited(n, false);
        visited[0] = true;
        for (int i = 0; i < n; ++i) {
            m[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                int t = q.front();
                q.pop();
                if (t == n - 1) {
                    return res;
                }
                if (t - 1 >= 0 && !visited[t-1]) {
                    q.push(t-1);
                    visited[t-1] = true;
                }
                if (t + 1 < n && !visited[t+1]) {
                    q.push(t+1);
                    visited[t+1] = true;
                }
                vector<int> nxt = m[arr[t]];
                for (auto const& x: nxt) {
                    if (!visited[x]) {
                        q.push(x);
                        visited[x] = true;
                    }
                }
                // to avoid TLE
                m[arr[t]].clear();
                --sz;
            }
            ++res;
        }
        return -1;
    }
};