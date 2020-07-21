#include "header.h"

#include "header.h"

class Solution {
public:
    bool dfs(int c, vector<int>& courses, vector<vector<int>>& graph, vector<int>& ans) {
        if (courses[c] == 1) {
            return false;
        } else if (courses[c] == 0) {
            courses[c] = 1;
            for (auto &i: graph[c]) {
                if (!dfs(i, courses, graph, ans)) {
                    return false;
                }
            }
            courses[c] = 2;
            ans.push_back(c);
        }
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> courses(numCourses, 0);
        vector<vector<int>> graph (numCourses, vector<int>());
        for (auto &v: prerequisites) {
            graph[v[1]].push_back(v[0]);
        }
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, courses, graph, ans)) {
                return vector<int> {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int n = 2;
    vector<vector<int>> p {{1,0}};
    auto ans = Solution().findOrder(n, p);
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}