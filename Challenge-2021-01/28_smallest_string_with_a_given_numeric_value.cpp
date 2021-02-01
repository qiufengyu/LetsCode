#include "../header.h"

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        int count = 0;
        for (int i = 0; i < n; i++) {
            res.push_back('a');
            count++;
        }
        int rest = k - count;
        int ri = n - 1;
        while (rest > 25) {
            res[ri--] = 'z';
            rest -= 25;
        }
        if (rest > 0) {
            res[ri] = (res[ri] + (rest));
        }
        return res;        
    }
};
