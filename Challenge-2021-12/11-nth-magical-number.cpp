#include "../header.h"

constexpr int MOD = 1000000007;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int l = lcm(a, b);
        long start = 0, end = 1e18;
        while (start < end) {
            long m = start + (end - start) / 2;
            if (m / a + m / b - m / l < n) {
                start = m + 1;
            } else {
                end = m;
            }
        }
        return (int)(start % MOD);
    }
};

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    return 0;
}