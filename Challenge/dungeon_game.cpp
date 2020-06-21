#include "header.h"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if (m == 0) {
            return 0;
        }
        int n = dungeon[0].size();
        vector<vector<int>> hp(m, vector<int>(n, INT_MAX));
        hp[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1]);
        for (int i = m - 2; i >= 0; i--) {
            hp[i][n-1] = max(1, hp[i+1][n-1] - dungeon[i][n-1]);
        }
        for (int j = n - 2; j >= 0; j--) {
            hp[m-1][j] = max(1, hp[m-1][j+1] - dungeon[m-1][j]);
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                // up -> down
                int temp1 = max(hp[i+1][j] - dungeon[i][j], 1);
                // left -> right
                int temp2 = max(hp[i][j+1] - dungeon[i][j], 1);
                hp[i][j] = min(temp1, temp2);
            }
        }        
        return hp[0][0];        
    }
};

// WA

// int m = dungeon.size();
// if (m == 0) {
//     return 0;
// }
// int n = dungeon[0].size();
// vector<vector<int>> hp(m, vector<int>(n, INT_MAX));
// vector<vector<int>> offset(m, vector<int>(n, 0));
// queue<pair<int, int>> q;
// q.push({0, 0});
// hp[0][0] = dungeon[0][0] > 0 ? 1 : 1 - dungeon[0][0];
// offset[0][0] = dungeon[0][0] > 0 ? dungeon[0][0] : 0;
// while (!q.empty()) {
//                 auto& p = q.front();
//     q.pop();
//     // cout << "pop " << p.first << ", " << p.second << endl;
//     int x = p.first, y = p.second;
//     int temp = 0;
//     if (x + 1 < m) {
//         if (dungeon[x+1][y] >= 0) {
//             hp[x+1][y] = min(hp[x][y], hp[x+1][y]);
//             offset[x+1][y] = offset[x][y] + dungeon[x+1][y];
//         } else {
//             hp[x+1][y] = min(hp[x][y] - dungeon[x+1][y] - offset[x][y], hp[x+1][y]);
//             if (hp[x+1][y] < 0) {
//                 hp[x+1][y] = hp[x][y];
//             }
//             offset[x+1][y] = offset[x][y] + dungeon[x+1][y];
//             if (offset[x+1][y] < 0) {
//                 offset[x+1][y] = 0;
//             }
//         }
//         q.push({x+1, y});
//     }
//     if (y + 1 < n) {
//         if (dungeon[x][y+1] >= 0) {
//             hp[x][y+1] = min(hp[x][y], hp[x][y+1]);
//             offset[x][y+1] = offset[x][y] + dungeon[x][y+1];
//         } else {
//             hp[x][y+1] = min(hp[x][y] - dungeon[x][y+1] - offset[x][y], hp[x][y+1]);
//             if (hp[x][y+1] < 0) {
//                 hp[x][y+1] = hp[x][y];
//             }
//             offset[x][y+1] = offset[x][y] + dungeon[x][y+1];
//             if (offset[x][y+1] < 0) {
//                 offset[x][y+1] = 0;
//             }
//         }
//         q.push({x, y+1});
//     }
// }
// return hp[m-1][n-1];  

int main() {
    vector<vector<int>> d {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << Solution().calculateMinimumHP(d) << endl;
}