#include "../header.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        return (n & (n-1)) == 0;        
        // unordered_set<int> s{1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
        // return s.find(n) != s.end();        
    }
};

int main() {
    int i = 1;
    for (int j = 0; j < 31; ++j) {
        cout << i << ",";
        i*=2;
    }
    return 0;
}