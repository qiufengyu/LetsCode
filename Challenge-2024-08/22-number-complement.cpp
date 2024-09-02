#include "../header.h"

class Solution {
public:
    int findComplement(int num) {
        unsigned mask = 0xffffffff;
        unsigned un = (unsigned) num;
        unsigned unxor = mask ^ un;
        while (un != 0) {
            un >>= 1;
            mask <<= 1;
        }
        unsigned mmask = ~mask;
        return unxor & mmask;
    }
};

int main() {
    cout << Solution().findComplement(1) << endl;
    return 0;
}