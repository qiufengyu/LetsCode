#include "../header.h"

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int, unordered_map<int, int>> g;
        for (auto const& e: edges) {
            g[e[0]][e[1]] = e[2];
            g[e[1]][e[0]] = e[2];
        }
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> HP;
        pq.emplace(maxMoves, 0);
        while (!pq.empty()) {
            auto t = pq.top();
            int hp = t.first, current = t.second;
            pq.pop();
            if (HP.count(current)) {
                continue;
            }
            HP[current] = hp;
            for (auto const& p: g[current]) {
                int next = p.first;
                int nextHP = hp - p.second - 1;
                if (HP.count(next) || nextHP < 0) {
                    continue;
                }
                pq.emplace(nextHP, next);
            }
        }
        int res = HP.size();
        for (auto const& e: edges) {
            int uv = HP.count(e[0]) ? HP[e[0]] : 0;
            int vu = HP.count(e[1]) ? HP[e[1]] : 0;
            res += min(e[2], uv + vu);
        }
        return res;
    }
};