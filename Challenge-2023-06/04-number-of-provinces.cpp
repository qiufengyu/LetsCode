#include "../header.h"

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), res = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++res;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int sz = q.size();
                    while (sz) {
                        int f = q.front();
                        q.pop();
                        for (int j = 0; j < n; ++j) {
                            if (f != j && isConnected[f][j] == 1 && (!visited[j])) {
                                q.push(j);
                                visited[j] = true;
                            }
                        }
                        --sz;
                    }
                }                
            }            
        }
        return res;
    }
};