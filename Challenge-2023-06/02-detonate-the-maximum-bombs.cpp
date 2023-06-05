#include "../header.h"

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> graph;
        int n = bombs.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    long long d2 = (long long)(bombs[i][0] - bombs[j][0]) * (long long)(bombs[i][0] - bombs[j][0]) + 
                            (long long)(bombs[i][1] - bombs[j][1]) * (long long)(bombs[i][1] - bombs[j][1]);
                    if ((long long)bombs[i][2] * bombs[i][2] >= d2) {
                        graph[i].push_back(j);
                    }
                }                
            }   
        }
        for (int i = 0; i < n; ++i) {
            vector<bool> detonated(n, false);            
            int tmp = 0;
            queue<int> q;
            detonated[i] = true;
            q.push(i);
            while (!q.empty()) {
                int sz = q.size();
                while (sz) {
                    int f = q.front();
                    q.pop();
                    ++tmp;                        
                    for (auto const& nbr: graph[f]) {
                        if (!detonated[nbr]) {
                            detonated[nbr] = true;
                            q.push(nbr);
                        }
                    }
                    --sz;
                }
            }
            res = max(res, tmp);            
        }
        return res;
    }
};