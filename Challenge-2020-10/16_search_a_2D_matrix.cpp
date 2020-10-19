#include "../header.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        int mIndex = 0;
        for (mIndex = 0; mIndex < m; mIndex++) {
            if (matrix[mIndex][n-1] >= target) {
                break;
            }
        }
        if (mIndex == m) {
            return false;
        }
        int nIndex = n - 1;
        for (nIndex = n - 1; nIndex >= 0; nIndex--) {
            if (matrix[mIndex][nIndex] == target) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    int target = 13;
    cout << Solution().searchMatrix(matrix, target) << endl;
    return 0;
}