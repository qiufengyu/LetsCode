#include "../header.h"

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, max(calc(A, B, i, j), calc(B, A, i, j)));
            }
        }
        return res;
    }

    int calc(vector<vector<int>>& A, vector<vector<int>>& B, int offsetX, int offsetY) {
        int sum = 0;
        int n = A.size();
        for (int i = offsetX; i < n; i++) {
            for (int j = offsetY; j < n; j++) {
                sum += A[i][j] * B[i - offsetX][j - offsetY];
            }
        }
        return sum;
    }
};

