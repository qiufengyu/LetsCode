#include "../header.h"

const int N = 1000000007;

class Solution {
public:
    int concatenatedBinary(int n) {
        return (int)helper(n);
    }
    
    long long helper(int n) {
        if (n == 1) {
            return 1L;
        }
        return (( helper(n-1) << ((int)log2(n)+1) ) + n) % N;
    }
    
};