#include "../header.h"

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), minDist = INT_MAX, res = -1;
        vector<int> dist1(n, -1), dist2(n, -1);
        dist1[node1] = 0;
        dist2[node2] = 0;
        dfs(edges, dist1, node1);
        dfs(edges, dist2, node2);
        for (int i = 0; i < n; ++i) {
            int m = max(dist1[i], dist2[i]);
            if (dist1[i] != -1 && dist2[i] != -1 && minDist > m) {
                minDist = m;
                res = i;
            }
        }
        return res;
    }

    void dfs(vector<int>& edges, vector<int>& dist, int node) {
        int neighbor = edges[node];
        if (neighbor != -1 && dist[neighbor] == -1) {
            dist[neighbor] = dist[node] + 1;
            dfs(edges, dist, neighbor);
        }
    }
};