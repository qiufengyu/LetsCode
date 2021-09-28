#include "../header.h"

class Solution {
public:
    int tribonacci(int n) {
        int f[38];
        memset(f, 0, sizeof(f));
        f[1] = 1;
        f[2] = 1;
        for (int i = 3; i <= n; ++i) {
            f[i] = f[i-1] + f[i-2] + f[i-3];
        }
        return f[n];
    }
};
