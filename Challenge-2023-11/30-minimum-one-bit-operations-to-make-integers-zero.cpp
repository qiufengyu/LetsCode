#include "../header.h"

class Solution {
public:
    int minimumOneBitOperations(int n) {
        unsigned int mask = (1 << 31);
        unsigned int start = (unsigned int)0xFFFFFFFF;
        long res = 0;        
        bool flag = true;
        for (int i = 0; i < 32; i++) {
            if ((n & mask) != 0) {
                if (flag) {
                    res += start;
                } else {
                    res -= start;
                }
                flag = !flag;
            }
            start = (start >> 1);
            mask = (mask >> 1);
        }
        return (int)res;
    }
};

int main() {
    cout << Solution().minimumOneBitOperations(6) << endl;
    return 0;
}