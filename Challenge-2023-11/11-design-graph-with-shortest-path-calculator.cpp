#include "../header.h"

typedef pair<int, int> PII;

class Graph {
    vector<vector<PII>> graph;
    int sz;
public:
    Graph(int n, vector<vector<int>>& edges): sz{n} {
        graph.resize(n);
        for (auto const& e: edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }        
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        // dijkstra
        vector<int> dist(sz, INT_MAX);
        dist[node1] = 0;
        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.push({0, node1});
        while (!pq.empty()) {
            int node = pq.top().second, cost = pq.top().first;
            pq.pop();
            if (cost > dist[node]) {
                continue;
            }
            if (node == node2) {
                return cost;
            }
            for (auto const& e: graph[node]) {
                int nbr = e.first, weight = e.second;
                int newCost = weight + dist[node];
                if (dist[nbr] > newCost) {
                    dist[nbr] = newCost;
                    pq.push({newCost, nbr});
                }
            }
        }
        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};