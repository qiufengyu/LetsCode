#include "../header.h"

class Solution {
public:
    int numSteps(string s) {
        int res = 0, n = s.size();
        for (int i = n - 1; i > 0; i--) {
            if (s[i] == '1') {
                s[i] = '0';
                int j = i - 1;
                while (j >= 0 && s[j] == '1') {
                    s[j] = '0';
                    j--;
                }
                if (j < 0) {
                    res++;
                } else {
                    s[j] = '1';
                }
                res++;
            }
            res++;
        }
        return res;
    }
};