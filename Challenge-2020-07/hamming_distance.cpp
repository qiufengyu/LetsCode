#include "header.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int res = 0;
        while (z) {
            res++;
            z = z & (z-1);
        }
        return res;
    }
};

int main() {
    int x, y;
    cin >> x >> y;
    cout << Solution().hammingDistance(x, y) << endl;
    return 0;
}