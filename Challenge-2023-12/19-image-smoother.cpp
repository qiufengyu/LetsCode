#include "../header.h"

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        int dirs[9][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int s = img[i][j], cnt = 1;
                for (int k = 0; k < 8; k++) {
                    int x = i + dirs[k][0], y = j + dirs[k][1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        s += img[x][y];
                        cnt++;
                    }
                }
                res[i][j] = s / cnt;
            }
        }
        return res;
    }
};