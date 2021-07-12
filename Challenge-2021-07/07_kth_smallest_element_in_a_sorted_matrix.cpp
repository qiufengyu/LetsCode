#include "../header.h"

class Solution {
public:
    bool count(vector<vector<int>>& matrix, const int k, const int n, const int mid) {
        int i = n - 1, j = 0, num = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                num += (i + 1);
                ++j;
            } else {
                --i;
            }
        }
        return num >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (count(matrix, k, n, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};