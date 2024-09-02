#include "../header.h"

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> probs (n, 0.0);
        vector<vector<pair<int, double>>> graph(n, vector<pair<int, double>>());
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        probs[start_node] = 1.0;
        queue<pair<int, double>> q;
        q.push({start_node, 1.0});
        while (!q.empty()) {
            auto frt = q.front();
            q.pop();
            for (auto nbr: graph[frt.first]) {
                double tmp = nbr.second * frt.second;
                if (tmp > probs[nbr.first]) {
                    probs[nbr.first] = tmp;
                    q.push({nbr.first, tmp});
                }
            }           
        }
        return probs[end_node];
    }
};