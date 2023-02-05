#include "../header.h"

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        return trib(n, 1, 0, 0);
    }

    int trib(int n, int a, int b, int c) {
        if (n == 1) {
            return a;
        }
        return trib(n-1, a + b + c, a, b);
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().tribonacci(n) << endl;
    return 0;
}