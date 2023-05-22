#include "../header.h"

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        vector<double> res;
        for (int i = 0; i < equations.size(); ++i) {
            auto e = equations[i];
            graph[e[0]][e[0]] = 1.0;
            graph[e[1]][e[1]] = 1.0;
            graph[e[0]][e[1]] = values[i];
            graph[e[1]][e[0]] = 1.0 / values[i];
        }
        for (auto const& qry: queries) {
            if (graph.count(qry[0]) == 0 || graph.count(qry[1]) == 0) {
                res.push_back(-1.0);
                continue;
            }
            queue<pair<string, double>> q;
            q.push({qry[0], 1.0});
            unordered_set<string> visited {qry[0]};
            bool found = false;
            while (!q.empty() && (!found)) {
                int sz = q.size();
                while (sz) {
                    auto t = q.front();
                    q.pop();
                    if (t.first == qry[1]) {
                        found = true;
                        res.push_back(t.second);
                        break;
                    }
                    for (auto const& g: graph[t.first]) {
                        if (visited.count(g.first) == 0) {
                            visited.insert(g.first);
                            q.push({g.first, g.second * t.second});
                        }
                    }
                    --sz;
                }
            }
            if (!found) {
                res.push_back(-1.0);
            }
        }
        return res;
    }
};