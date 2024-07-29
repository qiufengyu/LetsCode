#include "../header.h"

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 10001));
        for (int i = 0; i < edges.size(); i++) {
            int f = edges[i][0], t = edges[i][1], d = edges[i][2];
            dist[f][t] = d;
            dist[t][f] = d;
        }
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            auto di = dist[i];
            for (int j = 0; j < n; j++) {
                if (di[j] != 10001) {
                    for (int k = 0; k < n; k++) {
                        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                    }
                }
            }
        }
        // print_vector<int>(dist);
        unordered_map<int, int> mp;
        int mn = n;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] != 0 && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            mp[i] = count;
            mn = min(count, mn);
        }
        int res = 0;
        for (auto const& p: mp) {
            cout << p.first << " -> " << p.second << endl;
            if (p.second == mn) {
                res = max(res, p.first);
            }
        }
        return res;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> edges{{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;
    cout << Solution().findTheCity(n, edges, distanceThreshold) << endl;
    return 0;
}