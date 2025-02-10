#include "../header.h"

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res(A.size(), 0);
        unsigned long long an = 0ULL, bn = 0ULL;
        for (int i = 0; i < A.size(); i++) {
            an = (an | (1ULL << A[i]));
            bn = (bn | (1ULL << B[i]));
            res[i] = __builtin_popcountll((an & bn));
        }
        return res;
    }
};