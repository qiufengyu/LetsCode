#include "../header.h"

class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        int const M = 1000000007;
        char x = '0';
        long long count = 0LL;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (x == s[i]) {
                ++count;
            } else {
                res += (((count) * (count+1) / 2) % M);
                x = s[i];
                count = 1LL;
            }
        }
        res = (res + ((count) * (count+1) / 2) % M);
        return (int)res;
    }
};