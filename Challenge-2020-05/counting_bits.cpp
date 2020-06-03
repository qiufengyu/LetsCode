#include "header.h"

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        int bits = 0, x = num;
        while (x > 0) {
            bits++;
            x = x >> 1;
        }
        int start = 1;
        for (int i = 0; i < bits; i++) {
            for (int j = start; j < start * 2 && j <= num; j++) {
                res[j] = 1 + res[j-start];
            }
            start = start * 2;
            // res[j] = res[j & (j-1)] + 1;
        }
        return res;
    }
};

int main() {
    int num;
    cin >> num;
    for (auto &x: Solution().countBits(num)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}