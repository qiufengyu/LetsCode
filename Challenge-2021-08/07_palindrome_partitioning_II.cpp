#include "../header.h"

class Solution {
public:
    int minCut(string s) {
        int l = s.length();
        vector<vector<bool>> p(l, vector<bool>(l, true));
        for (int i = l - 1; i >= 0; --i) {
            for (int j = i + 1; j < l; ++j) {
                p[i][j] = p[i+1][j-1] && (s[i] == s[j]);
            }
        }
        vector<int> f(l, INT_MAX);
        for (int i = 0; i < l; ++i) {
            if (p[0][i]) {
                f[i] = 0;
            } else {
                for (int j = 0; j < i; ++j) {
                    if (p[j+1][i]) {
                        f[i] = min(f[i], f[j] + 1);
                    }
                }
            }
        }
        return f[l-1];
    }
};