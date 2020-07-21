#include "header.h"

class Solution {
public:
    double myPow(double x, int n) {
        unsigned int un = abs(n);
        double ans = 1.0;
        while (un) {
            if ((un & 1) == 1) {
                ans *= x;
            }
            un >>= 1;
            x = x * x;
        }
        return n > 0 ? ans : 1 / ans;
    }
};

int main() {
    double x;
    int n;
    cin >> x >> n;
    cout << Solution().myPow(x, n) << endl;
    return 0;
}