#include "../header.h"

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path = {};
        int size = graph.size();
        helper(graph, res, size, 0, path);
        return res;
    }

    void helper(vector<vector<int>>& graph, vector<vector<int>>& res, const int size, int current, vector<int>& path) {
        path.push_back(current);
        if (current == size - 1) {
            res.push_back(path);
        } else {
            for (auto t: graph[current]) {
                helper(graph, res, size, t, path);
            }
        }
        path.pop_back();
    }
};

int main() {
    vector<vector<int>> graph {{4,3,1},{3,2,4},{3},{4},{}};
    vector<vector<int>> res = Solution().allPathsSourceTarget(graph);
    print_vector<int>(res);
    return 0;
}