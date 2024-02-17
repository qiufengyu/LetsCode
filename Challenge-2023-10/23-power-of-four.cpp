#include "../header.h"

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        int zeors = 0;
        while ((n % 4) == 0) {
            zeors += 2;
            n = n >> 2;
        }
        return n == 1 && (zeors % 2 == 0);
    }
};

int main() {
    int n = 1;
    cout << Solution().isPowerOfFour(n) << endl;
    return 0;
}