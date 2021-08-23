#include "../header.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool flagRow = false, flagCol = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;                    
                    flagCol = flagCol || (j == 0);
                    flagRow = flagRow || (i == 0);
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i) {
                    matrix[i][j] = 0;
                }                
            }
        }    
        if (flagCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (flagRow) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }     
    }
};

int main() {
    vector<vector<int>> v {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    Solution().setZeroes(v);
    print_vector<int>(v);
    return 0;
}