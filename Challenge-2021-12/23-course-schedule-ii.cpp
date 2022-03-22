#include "../header.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> in(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>(0));
        queue<int> q;
        for (vector<int> const& p: prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++in[p[0]];
        }
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
            for (int const& e: graph[t]) {
                --in[e];
                if (in[e] == 0) {
                    q.push(e);
                }
            }
        }
        if (res.size() == numCourses) {
            return res;
        }
        return {};
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> c{{0,1},{0,2},{1,2}};
    vector<int> res = Solution().findOrder(n, c);
    print_vector<int>(res);
    return 0;
}