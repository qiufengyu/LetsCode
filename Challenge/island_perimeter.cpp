#include "header.h"

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int height = grid.size();
        if (height == 0) {
            return 0;
        }
        int width = grid[0].size();
        vector<vector<int>> h (height+1, vector<int>(width, 0));
        vector<vector<int>> v (width+1, vector<int>(height, 0));
        for (int x = 0; x < height; x++) {
            for (int y = 0; y < width; y++) {
                if (grid[x][y] == 1) {            
                    h[x][y] = 1 - h[x][y];
                    h[x+1][y] = 1 - h[x+1][y];
                    v[y][x] = 1 - v[y][x];
                    v[y+1][x] = 1 - v[y+1][x];
                }           
            }
        }
        int res = 0;
        for (int i = 0; i <= height; i++) {
            for (int j = 0; j < width; j++) {
                res += h[i][j];
            }
        }
        for (int i = 0; i <= width; i++) {
            for (int j = 0; j < height; j++) {
                res += v[i][j];
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> island {{0,1}};
    cout << Solution().islandPerimeter(island) << endl;
    return 0;
}