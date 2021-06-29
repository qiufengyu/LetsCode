#include "../header.h"

class Solution {
    vector<int> parent;
    int _find(int index) {
        if (parent[index] != index) {
            parent[index] = _find(parent[index]);
        }
        return parent[index];
    }

    void _union(int index1, int index2) {
        parent[_find(index1)]= _find(index2);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
        for (auto const& edge: edges) {
            int x = edge[0], y = edge[1];
            if (_find(x) != _find(y)) {
                _union(x, y);
            } else {
                return edge;
            }
        }
        return {};
    }
};