#include "../header.h"

class Solution {
    void dfs(vector<vector<int>>& g, vector<bool>& v, int& count, int i) {
        v[i] = true;
        ++count;
        for (auto const& n: g[i]) {
            if (!v[n]) {
                dfs(g, v, count, n);
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        for (auto const& c: edges) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        vector<int> counts;
        long long total = ((long long) n) * (n - 1) / 2;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int count = 0;
                dfs(graph, visited, count, i);
                total -= ((long long) count * (count - 1) / 2);
            }
        }
        // this is the timeout part:
        // if we calculate the sum of product of nodes in each part
        // long long res = 0LL;
        // for (int i = 0; i < counts.size(); ++i) {
        //     for (int j = i + 1; j < counts.size(); ++j) {
        //         res += ((long long) counts[i]) * counts[j];
        //     }
        // }        
        return total;
    }    
};

int main() {
    int n = 7;
    vector<vector<int>> edges {{0,2},{0,5},{2,4},{1,6},{5,4}};
    cout << Solution().countPairs(n, edges) << endl;
    return 0;
}