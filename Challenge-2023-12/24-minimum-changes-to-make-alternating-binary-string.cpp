#include "../header.h"

class Solution {
public:
    int minOperations(string s) {
        bool b0 = false, b1 = true;
        int r0 = 0, r1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                if (!b0) {
                    r0++;
                }
                if (!b1) {
                    r1++;
                }
            } else {
                if (b0) {
                    r0++;
                }
                if (b1) {
                    r1++;
                }
            }
            b0 = !b0;
            b1 = !b1;
        }
        return min(r0, r1);
    }
};        