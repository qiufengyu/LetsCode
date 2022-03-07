#include "../header.h"

class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) {
            return {0};
        }
        vector<int> res(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            if ((i & 1) == 0) {
                res[i] = res[i >> 1];
            } else {
                res[i] = 1 + res[i >> 1];
            }
        }
        return res;
    }
};
