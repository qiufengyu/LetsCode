#include "../header.h"

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        vector<double> res;
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]][equations[i][0]] = 1.0;
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][1]] = 1.0;
            graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
            
        }
        for (auto q: queries) {
            if (graph.count(q[0]) == 0 || graph.count(q[1]) == 0) {
                res.push_back(-1.0);
                continue;
            }
            queue<pair<string, double>> qq;
            unordered_set<string> visited {q[0]};
            bool flag = false;
            qq.push({q[0], 1.0});
            while (!qq.empty() && !flag) {
                for (int i = qq.size(); i > 0; i--) {
                    auto t = qq.front();
                    qq.pop();
                    if (t.first == q[1]) {
                        flag = true;
                        res.push_back(t.second);
                        break;
                    }
                    for (auto a: graph[t.first]) {
                        if (visited.count(a.first)) continue;
                        visited.insert(a.first);
                        a.second *= t.second;
                        qq.push(a);
                    }
                }
            }
            if (!flag) {
                res.push_back(-1.0);
            }
        }
        return res;
    }
};

