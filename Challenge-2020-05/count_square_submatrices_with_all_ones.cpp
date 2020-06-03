#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m=matrix[0].size();
        vector<vector<int> > dp;
        dp.assign(n+1, vector<int>(m+1,0));
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==1)
                    dp[i+1][j+1] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1]))+1;
                ans += dp[i+1][j+1];
            }
        }
        return ans;

        // int m = matrix.size();
        // int n = matrix[0].size();
        // int size = m < n ? m : n;
        // int res = 0;
        // queue<pair<int, int>> qp;
        // for (int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if (matrix[i][j] > 0) {
        //             qp.push({i, j});
        //             res += 1;
        //         }
        //     }
        // }
        // int s = 2;
        // int spSize = qp.size();        
        // while ( !qp.empty() && s <= size) {
        //     spSize = qp.size();
        //     int x = 0;
        //     int ss = s * s;
        //     while (x < spSize) {
        //         auto t = qp.front();
        //         qp.pop();
        //         // cout << t.first << ", " << t.second << ", " << s << endl;
        //         int y = 0;
        //         for(int i = t.first; i < t.first + s && i < m; i++) {
        //             for(int j = t.second; j < t.second + s && j < n; j++) {
        //                 y += matrix[i][j];
        //             }
        //         }
        //         if (y == ss) {
        //             res += 1;
        //             qp.push({t.first, t.second});
        //         }
        //         x++;
        //     }
        //     s++;
        // }
        // return res;        
    }

};

int main() {
    vector<vector<int>> matrix {
        {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}
    };
    cout << Solution().countSquares(matrix) << endl;
}