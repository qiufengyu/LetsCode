#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
const int inf = 999999;
int n, m;
vector<int> G[N], S[N];
int result;

int main() {
    scanf("%d%d", &n, &m);
    vector<int> Graph[N];
    for(int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        while(k--) {
            int x;
            scanf("%d", &x);
            G[x-1].push_back(i);
            S[i].push_back(x-1);
        }
    }
    // adjacency matrix
    for(int i = 0; i<n; ++i) {
        for(auto j: G[i]) {
            for(auto k: S[j]) {
                Graph[i].push_back(k);
            }
        }
    }
    // dijkstra
    bool visited[N] = {false};
    int distance[N];
    for(int i = 0; i<n; ++i) {
        distance[i] = inf;
    }
    distance[0] = 0;
    for(int i = 0; i<n; ++i) {
        int u = -1;
        int min_dist = inf;
        for(auto j: Graph[i]) {
            if(!visited[j] && distance[j] < min_dist) {
                u = j;
                min_dist = distance[j];
            }
        }
        if(u == -1) break;
        visited[u] = true;
        vector<int> GraphU = Graph[u];
        for(auto v: GraphU) {
            if(!visited[v]) {
                if(distance[u] + 1 < distance[v]) {
                    distance[v] = distance[u] + 1;
                }
            }
        }
    }
    result = distance[n-1];

    printf("%d\n", result);
    return 0;
}