#include "header.h"

class Solution {
public:
    bool dfs(int c, vector<int>& courses, vector<vector<int>>& graph) {
        if (courses[c] == 1) {
            return false;
        } else if (courses[c] == 0) {
            courses[c] = 1;
            for (auto &i: graph[c]) {
                if (!dfs(i, courses, graph)) {
                    return false;
                }
            }
            courses[c] = 2;
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> courses(numCourses, 0);
        vector<vector<int>> graph (numCourses, vector<int>());
        for (auto &v: prerequisites) {
            graph[v[1]].push_back(v[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, courses, graph)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n = 2;
    vector<vector<int>> p {{1,0}};
    cout << Solution().canFinish(n, p);
    cout << endl;
    return 0;

}