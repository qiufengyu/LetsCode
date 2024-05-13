#include "../header.h"

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
		if (n == 1) {
			return {0};
		}
		if (n == 2) {
			return {0, 1};
		}
		for (auto const& edge: edges) {
			graph[edge[0]].insert(edge[1]);
			graph[edge[1]].insert(edge[0]);
		}
		queue<int> q;
		for (auto const& p: graph) {
			if (p.second.size() == 1) {
				q.push(p.first);
			}
		}
		while (n > 2) {
			int sz = q.size();
			n -= sz;
			while (sz) {
				int frt = q.front();
				q.pop();
				int nbr = *graph[frt].begin();
				graph[nbr].erase(frt);
				if (graph[nbr].size() == 1) {
					q.push(nbr);
				}
				sz--;
			}
		}
		vector<int> res;
		while (!q.empty()) {
			res.push_back(q.front());
			q.pop();
		}
		return res;
    }
};