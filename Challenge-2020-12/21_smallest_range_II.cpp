#include "../header.h"

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int sz = A.size();        
        int l = A[0] + K;
        int r = A[sz-1] - K;
        int res = A[sz-1] - A[0];
        for (int i = 0; i < sz - 1; i++) {
            int a = min(l, A[i+1] - K);
            int b = max(r, A[i] + K);
            res = min(res, b - a);
        }
        return res;
    }
};