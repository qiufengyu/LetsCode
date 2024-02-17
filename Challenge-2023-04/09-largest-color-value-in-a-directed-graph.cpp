#include "../header.h"

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> colorCount(n, vector<int>(26, 0));
        vector<bool> visited(n, false);
        vector<bool> currentRound(n, false);
        vector<vector<int>> graph(n);
        for (auto e: edges) {
            graph[e[0]].push_back(e[1]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, dfs(colors, graph, colorCount, visited, currentRound, i));
        }        
        return res == INT_MAX ? -1 : res;
    }

    int dfs(const string& colors, vector<vector<int>>& graph, vector<vector<int>>& colorCount, vector<bool>& visited, 
            vector<bool>& currentRound, int node) {
        if (currentRound[node]) {
            return INT_MAX;
        }
        if (visited[node]) {
            return colorCount[node][colors[node] - 'a'];
        }
        currentRound[node] = true;
        visited[node] = true;
        for (auto neighbor: graph[node]) {          
            if (dfs(colors, graph, colorCount, visited, currentRound, neighbor) == INT_MAX) {
                return INT_MAX;
            }
            for (int i = 0; i < 26; ++i) {
                colorCount[node][i] = max(colorCount[node][i], colorCount[neighbor][i]);
            }                 
        }
        colorCount[node][colors[node]-'a']++;
        currentRound[node] = false;
        return colorCount[node][colors[node]-'a'];
    }
};