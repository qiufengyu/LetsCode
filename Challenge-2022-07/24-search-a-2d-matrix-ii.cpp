#include "../header.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = n - 1, j = 0;
        while (i >= 0 && j < m) {
            if (matrix[j][i] == target) {
                return true;
            } else if (matrix[j][i] > target) {
                --i;
            } else {
                ++j;
            }
        }        
        return false;
    }
};