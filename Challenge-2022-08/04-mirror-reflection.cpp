#include "../header.h"

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = p * q / __gcd(p, q);
        int m = lcm / p, n = lcm / q;
        if (m % 2 == 0) {
            return 0;
        }
        return n % 2 == 0 ? 2 : 1;        
    }
};