#include "../header.h"

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
      int m = box.size();
        int n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[j][m-i-1] = box[i][j];
            }
        }
        // for each column in res, move the stones
        for (int i = 0; i < m; ++i) {
            int currentStone = 0, obstacleIndex = -1;
            for (int j = 0; j <= n; ++j) {
                if (j < n && res[j][i] == '#') {
                    ++currentStone;
                }
                else if (j == n || res[j][i] == '*') {
                    for (int k = obstacleIndex + 1; k < j; ++k) {
                        if (k + currentStone < j) {
                            res[k][i] = '.';
                        } else {
                            res[k][i] = '#';
                        }
                    }
                    currentStone = 0;
                    obstacleIndex = j;
                }
            }
        }
        return res;
    }
};

int main() {
  vector<vector<char>> box {{'#','#','*','.','*','.'},
              {'#','#','#','*','.','.'},
              {'#','#','#','.','#','.'}};
  vector<vector<char>> res = Solution().rotateTheBox(box);
  print_vector(res);
  return 0;
}