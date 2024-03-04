#include "../header.h"

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones++;
            }
        }
        string res(n, '0');
        for (int i = 0; i < ones - 1; i++) {
            res[i] = '1';
        }
        res[n-1] = '1';
        return res;
    }
};