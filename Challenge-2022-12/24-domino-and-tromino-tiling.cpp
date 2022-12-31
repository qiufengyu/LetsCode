#include "../header.h"

class Solution {
public:
    int numTilings(int n) {
        vector<long> res(n+1, 0L);
        if (n <= 2) {
            return n;
        }
        res[1] = 1;
        res[2] = 2;
        res[3] = 5;
        for (int i = 4; i <= n; ++i) {
            res[i] = ((res[i-3]) + (2 * res[i-1])) % 1000000007;
        }
        return res[n];
    }
};