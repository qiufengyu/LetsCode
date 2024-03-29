#include "../header.h"

typedef pair<int, int> PII;

struct cmp {
    bool operator()(PII const& p1, PII const& p2) {
        if (p1.first == p2.first) {
            return p1.second > p2.second;
        }
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<PII, vector<PII>, cmp> pq;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            int s = accumulate(mat[i].begin(), mat[i].end(), 0);
            pq.emplace(s, i);
        }
        vector<int> res;
        while (k > 0) {
            res.push_back(pq.top().second);
            pq.pop();
            --k;
        }
        return res;
    }
};