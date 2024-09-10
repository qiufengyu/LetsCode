#include "../header.h"

inline int getNum(int x) {
    int r = 0;
    while (x) {
        r += x % 10;
        x /= 10;
    }
    return r;
}

class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        k--;
        for (int i = 0; i < s.size(); i++) {
            res += getNum(s[i] - 'a' + 1);
        }
        while (k) {
            res = getNum(res);
            k--;
        }
        return res;
    }
};