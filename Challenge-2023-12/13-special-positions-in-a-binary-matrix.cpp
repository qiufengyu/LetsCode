#include "../header.h"

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> vm(m, 0), vn(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    ++vm[i];
                    ++vn[j];
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && vm[i] == 1 && vn[j] == 1) {
                    ++res;
                }
            }
        }
        return res;
    }
};