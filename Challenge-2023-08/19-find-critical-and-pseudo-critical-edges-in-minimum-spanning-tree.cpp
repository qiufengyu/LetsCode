#include "../header.h"

class UF {
    vector<int> parent;
public:
    UF(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void uni(int x, int y) {
        int px = find(x), py = find(y);
        parent[px] = py;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical, pscritical;
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[2] < b[2];
        });
        int mstWeight = findMST(n, edges, -1, -1);
        for (int i = 0; i < edges.size(); i++) {
            if (mstWeight < findMST(n, edges, i, -1)) {
                critical.push_back(edges[i][3]);
            } else if (mstWeight == findMST(n, edges, -1, i)) {
                pscritical.push_back(edges[i][3]);
            }
        }
        return {critical, pscritical};
    }

    int findMST(int n, vector<vector<int>>& edges, int block, int e) {
        UF uf(n);
        int weight = 0;
        if (e != -1) {
            weight += edges[e][2];
            uf.uni(edges[e][0], edges[e][1]);
        }
        for (int i = 0; i < edges.size(); i++) {
            if (i == block) {
                continue;
            }
            if (uf.find(edges[i][0]) == uf.find(edges[i][1])) {
                continue;
            }
            uf.uni(edges[i][0], edges[i][1]);
            weight += edges[i][2];
        }
        for (int i = 0; i < n; i++) {
            if (uf.find(i) != uf.find(0)) {
                return INT_MAX;
            }
        }
        return weight;
    }
};