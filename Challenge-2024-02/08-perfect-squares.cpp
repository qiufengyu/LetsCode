#include "../header.h"

inline bool isSquare(int n) {
    int x = (int)sqrt((double)n);
    return x * x == n;
}

class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) {
            return 4;
        }
        if (isSquare(n)) {
            return 1;
        }
        for (int i = 1; i * i <= n; i++) {
            int y = n - i * i;
            if (isSquare(y)) {
                return 2;
            }
        }
        return 3;
    }
};