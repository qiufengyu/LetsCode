#include "../header.h"

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int mn = max(m, n);
        vector<priority_queue<int,vector<int>, greater<int> > > v(m+n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v[i - j + n].push(mat[i][j]);
            }
        }
        // recover
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = v[i - j + n].top();
                v[i-j+n].pop();
            }
        }
        return mat;   
    }
};
