#include "../header.h"

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        return (num & (num - 1)) == 0 && (num & 0x55555555) == num;
    }
};

int main() {
    int num;
    cin >> num;
    cout << Solution().isPowerOfFour(num) << endl;
    return 0;
}