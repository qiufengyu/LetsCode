#include "../header.h"

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, pair<string, double>> parents;
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0], b = equations[i][1];
            double k = values[i];
            if (!parents.count(a) && !parents.count(b)) {
                parents[a] = {b, k};
                parents[b] = {b, 1.0};
            } else if (!parents.count(a)) {
                parents[a] = {b, k};
            } else if (!parents.count(b)) {
                parents[b] = {a, 1.0 / k};
            } else {
                pair<string, double> ra = find(a, parents);
                pair<string, double> rb = find(b, parents);
                if (ra.first != rb.first) {
                    parents[ra.first] = {rb.first, rb.second * k / ra.second};
                }
            }
        }
        vector<double> res;
        for (auto const& q: queries) {
            string x = q[0], y = q[1];
            if (!parents.count(x) || !parents.count(y)) {
                res.push_back(-1.0);
                continue;
            }
            pair<string, double> rx = find(x, parents);
            pair<string, double> ry = find(y, parents);
            if (rx.first != ry.first) {
                res.push_back(-1.0);
            } else {
                res.push_back(rx.second / ry.second);
            }
        }
        return res;
    }

    pair<string, double> find(string const& c, unordered_map<string, pair<string, double>> parents) {
        if (c != parents[c].first) {
            pair<string, double> p = find(parents[c].first, parents);
            parents[c].first = p.first;
            parents[c].second *= p.second;
        }
        return parents[c];
    }
};

int main() {
    vector<vector<string>> equations {{"a","b"},{"b","c"}};
    vector<double> values {2.0,3.0};
    vector<vector<string>> queries {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    vector<double> res = Solution().calcEquation(equations, values, queries);
    print_vector<double>(res);
    return 0;
}
