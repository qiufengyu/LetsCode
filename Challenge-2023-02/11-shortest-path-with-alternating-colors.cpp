#include "../header.h"

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<int>> redGraph, blueGraph;
        vector<int> redRes(n, -1), blueRes(n, -1);
        for (auto const& re: redEdges) {
            if (redGraph.count(re[0])) {
                redGraph[re[0]].push_back(re[1]);
            } else {
                redGraph[re[0]] = {re[1]};
            }
        }
        for (auto const& be: blueEdges) {
            if (blueGraph.count(be[0])) {
                blueGraph[be[0]].push_back(be[1]);
            } else {
                blueGraph[be[0]] = {be[1]};
            }
        }
        queue<int> rq, bq;
        rq.push(0);
        bq.push(0);
        int l = 0;
        blueRes[0] = 0;
        redRes[0] = 0;
        while ((!rq.empty()) || (!bq.empty())) {
            ++l;
            int rsz = rq.size();
            int bsz = bq.size();
            while (rsz > 0) {
                int r = rq.front();
                rq.pop();
                for (auto const& b: blueGraph[r]) {
                    if (blueRes[b] == -1 || blueRes[b] == l) { // not visited
                        blueRes[b] = l;
                        bq.push(b);
                    }
                }
                --rsz;
            }
            while (bsz > 0) {
                int b = bq.front();
                bq.pop();
                for (auto const& r: redGraph[b]) {
                    if (redRes[r] == -1 || redRes[r] == l) {
                        redRes[r] = l;
                        rq.push(r);
                    }
                }
                --bsz;
            }            
        }
        for (int i = 0; i < n; ++i) {
            if (redRes[i] == -1) {
                redRes[i] = blueRes[i];
            } else if (blueRes[i] != -1){
                redRes[i] = min(redRes[i], blueRes[i]);
            }
        }
        return redRes;
    }
};