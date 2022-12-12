#include "../header.h"

class Solution {
public:
    int climbStairs(int n) {
        return fibTail(n, 1, 0);
    }

    int fibTail(int n, int a, int b) {
        if (n == 0) {
            return a; 
        } else {
            return fibTail(n-1, a+b, a);
        }
    }
};
