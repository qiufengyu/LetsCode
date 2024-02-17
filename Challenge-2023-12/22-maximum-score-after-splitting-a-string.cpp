#include "../header.h"

class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ++ones;
            }
        }
        int z = 0, res = 0;
        // considering case s = "0000", res = 3
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                ++z;
            }
            res = max(res, z + ones - (i+1-z));
        }
        return res;
    }
};