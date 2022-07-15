#include "../header.h"

class Solution {
public:
    int fib(int n) {
        return fibTailRec(n, 0, 1);
    }

    int fibTailRec(int n, int a, int b) {
        if (n == 0) {
            return a;
        } else {
            return fibTailRec(n - 1, a + b, a);
        }
    }
};