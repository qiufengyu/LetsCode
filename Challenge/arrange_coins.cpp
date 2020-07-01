#include "header.h"

class Solution {
public:
    int arrangeCoins(int n) {
        return (int) (sqrt(8 * (double)n + 1) - 1) / 2;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().arrangeCoins(n) << endl;
    return 0;
}