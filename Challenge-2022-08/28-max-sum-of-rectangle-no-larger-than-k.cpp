#include "../header.h"

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int r = matrix.size(), c = matrix[0].size();
        int mx = INT_MIN;
        for (int i = 0; i < c; ++i) {
            int rowSum[101] = {0};
            for (int j = i; j < c; ++j) {
                for (int l = 0; l < r; ++l) {
                    rowSum[l] += matrix[l][j];
                }
                mx = max(mx, dpmax(rowSum, k, r));
                if (mx == k) {
                    return k;
                }
            }            
        }
        return mx;
    }

    int dpmax(int arr[], int k, int rSize) {
        int rollSum = arr[0], rollMax = rollSum;
        for (int i = 1; i < rSize; ++i) {
            if (rollSum > 0) {
                rollSum += arr[i];
            } else {
                rollSum = arr[i];
            }
            rollMax = max(rollMax, rollSum);
        }
        if (rollMax <= k) {
            return rollMax;
        }
        int mx = INT_MIN;
        for (int i = 0; i < rSize; ++i) {
            int sum = 0;
            for (int j = i; j < rSize; ++j) {
                sum += arr[j];
                if (sum > mx && sum <= k) {
                    mx = sum;
                }
                if (mx == k) {
                    return k;
                }
            }
        }
        return mx;
    }
};