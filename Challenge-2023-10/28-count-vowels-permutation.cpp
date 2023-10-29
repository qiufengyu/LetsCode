#include "../header.h"

class Solution {
public:
    int countVowelPermutation(int n) {
        int const M = 1000000007;
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        while (n > 1) {
            long aa = (e + i) % M + u % M;
            long ee = (a + i) % M;
            long ii = (e + o) % M;
            long oo = i % M;
            long uu = (i + o) % M;
            a = aa;
            e = ee;
            i = ii;
            o = oo;
            u = uu;
            --n;
        }
        return (int)(((a + e) % M + i % M + (o + u) % M) % M);
    }
};