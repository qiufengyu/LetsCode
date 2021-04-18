#include "../header.h"

class Solution {
public:
    int fib(int n) {
        return fibTail(n, 0, 1);
    }
    int fibTail(int n, int res, int step) {
        if (n == 0) {
            return res;
        }
        else {
            return fibTail(n-1, step, res + step);
        }
    }
};