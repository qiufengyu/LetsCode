#include "../header.h"

class Solution {
public:
    int countArrangement(int n) {
        vector<bool> visited(n+1, false);
        int res = 0;
        helper(n, visited, 1, res);
        return res;
    }

    void helper(int n, vector<bool>& visited, int current, int& res) {
        if (current > n) {
            res++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (i % current == 0 || current % i == 0)) {
                visited[i] = true;
                helper(n, visited, current+1, res);
                visited[i] = false;
            }
        }
    }
};
