#include "../header.h"

class Solution {
public:
    int reachNumber(int target) {
        int t = abs(target);
        int n = ceil((-1.0 + sqrt(1 + 8.0 * t)) / 2);
        int sum = n * (n + 1) / 2;
        int res = sum - t;
        if (res % 2 == 0) {
            return n;
        } else {
            return n + ((n % 2 == 0) ? 1 : 2);
        }
    }
};
