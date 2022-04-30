#include "../header.h"

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int> > > m;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                m.push_back(make_pair(cost, make_pair(i, j)));
            }
        }
        // MST algo
        sort(m.begin(), m.end(), [](const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b) -> bool {
            return a.first < b.first;
        });
        int res = 0;
        vector<int> visited(n, -1);
        for (int i = 0; i < m.size(); ++i) {            
            auto edge = m[i];                        
            int node1 = findNode(visited, edge.second.first);
            int node2 = findNode(visited, edge.second.second);            
            if (node1 != node2) {
                res += edge.first;
                visited[node2] = node1;
            }
        }
        return res;
    }

    // Union-Find
    int findNode(vector<int>& visited, int i) {
        if (visited[i] < 0) {
            return i;
        } else {
            visited[i] = findNode(visited, visited[i]);
            return visited[i];
        }
    }
};

int main() {
    vector<vector<int>> points {{2,-3},{-17,-8},{13,8},{-17,-15}};
    cout << Solution().minCostConnectPoints(points) << endl;
    return 0;
}