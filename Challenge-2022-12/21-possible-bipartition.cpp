#include "../header.h"

class Solution {
public:
    bool possibleBipartitionUtil(vector<vector<int>>& dislikes, vector<int> &v, int node) {
        queue<int> q;
        q.push(node);
        v[node] = 1;
        while (!q.empty()) {
            int t = q.front();
            for(auto &d: dislikes) {
                if (d[0] == t) {
                    if (v[d[1]] == 0) {
                        q.push(d[1]);
                        v[d[1]] = v[t] == 1 ? 2 : 1;
                    } else if (v[d[1]] == v[t]) {
                        return false;
                    }
                } else if (d[1] == t) {
                    if (v[d[0]] == 0) {
                        q.push(d[0]);
                        v[d[0]] = v[t] == 1 ? 2 : 1;
                    } else if (v[d[0]] == v[t]) {
                        return false;
                    }
                }
            }
            q.pop();
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {        
        if (dislikes.size() <= 1) {
            return true;
        }
        vector<int> v (N + 1, 0);        
        for (int i = 1; i < N + 1; i++) {
            if (v[i] == 0) {
                if (!possibleBipartitionUtil(dislikes, v, i)) {
                    return false;
                }
            }            
        }
        return true;
    }
};