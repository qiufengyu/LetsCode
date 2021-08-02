#include "../header.h"

const int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> pending(m, vector<bool>(n, true)); 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.emplace(i, j);
                    pending[i][j] = false;
                }
            }
        }
        int round = 0;
        while (!q.empty()) {
            ++round;
            int sz = q.size();
            for (int s = 0; s < sz; ++s) {
                auto t = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int x = t.first + directions[d][0], y = t.second + directions[d][1];
                    if (x >= 0 && x < m && y >= 0 && y < n && pending[x][y]) {
                        mat[x][y] = round;
                        pending[x][y] = false;
                        q.emplace(x, y);
                    }
                }
            }
        }
        return mat;
    }
};

int main() {
    vector<vector<int>> mat {{0,0,0},{0,1,0},{1,1,1}};
    auto res = Solution().updateMatrix(mat);
    print_vector<int>(res);
    return 0;
}
