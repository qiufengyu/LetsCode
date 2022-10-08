#include "../header.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n+1) / 2; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                int temp = matrix[j][i];                
                matrix[j][i] = matrix[n-1-i][j];
                matrix[n-1-i][j] = matrix[n-1-j][n-1-i];
                matrix[n-1-j][n-1-i] = matrix[i][n-1-j];
                matrix[i][n-1-j] = temp;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution().rotate(matrix);
    print_vector<int>(matrix);
    return 0;
}