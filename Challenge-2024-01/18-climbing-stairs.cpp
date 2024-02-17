#include "../header.h"

class Solution {
public:
    int climbStairs(int n) {
        return fib(n, 1, 0);        
    }

    int fib(int a, int b, int c) {
        if (a == 0) {
            return b;
        }
        return fib(a - 1, b + c, b);
    }
};

int main() {
    int x = 6;
    cout << Solution().climbStairs(x) << endl;
    return 0;
}