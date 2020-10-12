#include "../header.h"

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) {
            return 1;
        }
        unsigned M = 0xffffffff & N;
        unsigned mask = 0;
        while (N != 0) {
            mask = mask * 2 + 1;
            N /= 2;
        }
        int res = mask & (~M);
        return res;        
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().bitwiseComplement(n) << endl;
    return 0;
}