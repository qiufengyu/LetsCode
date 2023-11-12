#include "../header.h"

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        int n = adjacentPairs.size() + 1;
        for (auto const& p: adjacentPairs) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        // find the start node with only one neighbor
        int node = 100001;
        for (auto const& p: graph) {
            if (p.second.size() == 1) {
                node = p.first;
                break;
            }
        }
        vector<int> res(n, 100001);
        int index = 0;
        while (index < n) {
            res[index] = node;
            auto adjs = graph[node];            
            if (adjs.size() == 1) {
                node = adjs[0];
            } else {
                if (adjs[0] == res[index-1]) {
                    node = adjs[1];
                } else {
                    node = adjs[0];
                }
            }
            index++;          
        }
        return res;
    }
};

int main() {
    vector<vector<int>> ap {{2,1}, {3,4}, {3,2}};
    auto res = Solution().restoreArray(ap);
    print_vector<int>(res);
    return 0;
}