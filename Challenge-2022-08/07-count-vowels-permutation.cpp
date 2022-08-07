#include "../header.h"

int const M = 1000000007;

class Solution {
public:
    int countVowelPermutation(int n) {
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int j = 1; j < n; ++j) {
            long aa = (e + i + u) % M;
            long ee = (a + i) % M;
            long ii = (e + o) % M;
            long oo = i % M;
            long uu = (i + o) % M;
            a = aa;
            e = ee;
            i = ii;
            o = oo;
            u = uu;
        }
        return (int)((a + e + i + o + u) % M);        
    }
};