#include "../header.h"

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1, 0), out(n + 1, 0);
        for (vector<int> const& t: trust) {
            ++in[t[1]];
            ++out[t[0]];
        }
        for (int i = 1; i <= n; ++i) {
            if (out[i] == 0 && in[i] == n - 1) {
                return i;
            } 
        }
        return -1;
    }
};