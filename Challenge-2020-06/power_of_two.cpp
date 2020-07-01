#include "header.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        return (n & (n-1)) == 0;
    }
};

int main() {
    cout << Solution().isPowerOfTwo(10086) << endl;
    return 0;
}
